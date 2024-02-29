#include<iostream>
#include<vector>
#include<random>
#include<set>
#include<string.h>
#include<windows.h>
#include<time.h>
#include<math.h>
#include<algorithm>
//�ɵ�����
#define MAXN 25
#define wall_char '#'
#define road_char '.'
#define search_char '@'
#define end_char '*'
#define cold_down 1
#define INF 0x3fffffff
using namespace std;
char maze[MAXN * 2 + 1][MAXN * 2 + 1];
bool access[MAXN * 2 + 1][MAXN * 2 + 1];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
pair<int,int>mazestart,mazeend;
pair<int, int>fa[MAXN * 2 + 1][MAXN * 2 + 1];
struct Data {
	int x;
	int y;
	double distance;//ģ��ŷ����þ���
	inline Data() {
		this->x = 0;
		this->y = 0;
		this->distance = INF;
	}
	inline Data(int a, int b) {
		this->x = a;
		this->y = b;
		this->distance = (a - mazeend.first)*(a - mazeend.first) + (b - mazeend.second)*(b - mazeend.second);
	}
	bool operator<(const Data& other)const {
		return this->distance < other.distance;
	}
}heap[1000];//����ģ���
pair<int, int> st[1000];//����ģ��ջ
pair<int, int> qu[4000];//����ģ�����
bool found = 0;//�ݹ麯���Ƿ����
void up(int ind) {//ģ���ϸ�
	if (ind / 2 && heap[ind] < heap[ind / 2]) {
		swap(heap[ind / 2], heap[ind]);
		up(ind / 2);
	}
}
void down(int ind,int sz) {//ģ���³�
	int t = ind;
	if (2 * ind<=sz && heap[2 * ind] < heap[t])t = 2 * ind;
	if (2 * ind + 1<=sz && heap[2 * ind + 1] < heap[t])t = 2 * ind + 1;
	if (t != ind) {
		swap(heap[ind], heap[t]);
		down(t,sz);
	}
}
void pop(int &sz) {//ģ�ⵯ��
	heap[1] = heap[sz--];
	down(1,sz);
}
void inse(int &sz, Data x) {//ģ�����
	heap[++sz] = x;
	up(sz);
}
void output(int size) {//����Թ�
	int length = size * 2 + 1;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			if (maze[i][j] == search_char) {
				cout << "\033[92m" << maze[i][j] << "\033[0m ";
			}
			else if (maze[i][j] == end_char) {
				cout << "\033[31m" << maze[i][j] << "\033[0m ";
			}
			else cout << maze[i][j] << ' ';
		}
		cout << endl;
	}
}
void trace(int size,int time) {//Ѱ�ҿɳ��Թ��Ĺ켣
	pair<int, int>i=mazeend;
	while (i != mazestart) {
		maze[i.first][i.second] = end_char;
		system("cls");
		cout << "�ɹ��߳��Թ���������" << time << endl;
		output(size);
		i = fa[i.first][i.second];
		Sleep(cold_down);
	}
	maze[i.first][i.second] = end_char;
	system("cls");
	cout << "�ɹ��߳��Թ���������" << time << endl;
	output(size);
}
void init(int size) {//��ʼ���Թ�
	int length = 2 * size + 1;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			maze[i][j] = wall_char;
		}
	}
	for (int i = 0; i < length / 2; i++) {
		for (int j = 0; j < length / 2; j++) {
			maze[1 + 2 * i][1 + 2 * j] = road_char;
		}
	}
}
void start_and_end(int size) {//���������������
	int length = size * 2 + 1;
	int maze_start = rand() % size;
	int maze_end = rand() % size;
	int start_side = rand() % 4;
	if (start_side == 0) {
		mazestart = pair<int, int>(0, 2 * maze_start + 1);
		mazeend = pair<int, int>(length - 1, 2 * maze_end + 1);
	}
	else if (start_side == 1) {
		mazestart = pair<int, int>(2 * maze_start + 1, length - 1);
		mazeend = pair<int, int>(2 * maze_end + 1, 0);
	}
	else if (start_side == 2) {
		mazestart = pair<int, int>(length - 1, 2 * maze_start + 1);
		mazeend = pair<int, int>(0, 2 * maze_end + 1);
	}
	else if (start_side == 3) {
		mazestart = pair<int, int>(2 * maze_start + 1, 0);
		mazeend = pair<int, int>(2 * maze_end + 1, length - 1);
	}
	maze[mazestart.first][mazestart.second] = search_char;
	maze[mazeend.first][mazeend.second] = end_char;
}
void mazeGenerator_Prim(int size) {//����prim���Թ�����
	int length = 2 * size + 1;
	//��ȡ�Թ�������
	srand(time(0));

	//��ʼ���Թ�

	init(size);

	//���ó��ڡ����

	start_and_end(size);

	//��ʼ�����Թ�

	vector<pair<int, int>>wall;
	bool access[MAXN * 2 + 1][MAXN * 2 + 1];
	memset(access, 0, sizeof(access));
	access[1][1] = 1;
	wall.push_back(pair<int, int>(1, 2));
	wall.push_back(pair<int, int>(2, 1));
	while (!wall.empty()) {
		int select_wall = rand() % wall.size();
		vector<pair<int, int>>::iterator it = wall.begin();
		it += select_wall;
		int wx = it->first;
		int wy = it->second;
		wall.erase(it);
		if (wx % 2 == 0 && (access[wx - 1][wy] ^ access[wx + 1][wy])) {
			maze[wx][wy] = road_char;
			if (access[wx - 1][wy]) {
				int x = wx + 1;
				int y = wy;
				access[x][y] = 1;
				for (int i = 0; i < 4; i++) {
					if (x + dx[i] != wx && y + dy[i] != wy && x + dx[i] > 0 && y + dy[i] > 0 && x + dx[i] < length - 1 && y + dy[i] < length - 1) {
						wall.push_back(pair<int, int>(x + dx[i], y + dy[i]));
					}
				}
			}
			else {
				int x = wx - 1;
				int y = wy;
				access[x][y] = 1;
				for (int i = 0; i < 4; i++) {
					if (x + dx[i] != wx && y + dy[i] != wy && x + dx[i] > 0 && y + dy[i] > 0 && x + dx[i] < length - 1 && y + dy[i] < length - 1) {
						wall.push_back(pair<int, int>(x + dx[i], y + dy[i]));
					}
				}
			}
		}
		else if (wx % 2 == 1 && (access[wx][wy - 1] ^ access[wx][wy + 1])) {
			maze[wx][wy] = road_char;
			if (access[wx][wy - 1]) {
				int x = wx;
				int y = wy + 1;
				access[x][y] = 1;
				for (int i = 0; i < 4; i++) {
					if (x + dx[i] != wx && y + dy[i] != wy && x + dx[i] > 0 && y + dy[i] > 0 && x + dx[i] < length - 1 && y + dy[i] < length - 1) {
						wall.push_back(pair<int, int>(x + dx[i], y + dy[i]));
					}
				}
			}
			else {
				int x = wx;
				int y = wy - 1;
				access[x][y] = 1;
				for (int i = 0; i < 4; i++) {
					if (x + dx[i] != wx && y + dy[i] != wy && x + dx[i] > 0 && y + dy[i] > 0 && x + dx[i] < length - 1 && y + dy[i] < length - 1) {
						wall.push_back(pair<int, int>(x + dx[i], y + dy[i]));
					}
				}
			}
		}
	}
}
void mazeGenerator_Random(int size,int weight) {//��������Թ�
	int length = 2 * size + 1;
	//��ȡ�Թ�������
	srand(time(0));

	//��ʼ���Թ�

	init(size);

	//���ó��ڡ����

	start_and_end(size);

	//��ʼ�����Թ�
	int road_num = weight * (length - 2) * (length - 2) / 10;
	for (int i = 0; i < road_num; i++) {
		int x = rand() % (length - 2) + 1;
		int y = rand() % (length - 2) + 1;
		maze[x][y] = road_char;
	}
}
void mazeTraverse_dfs(int size) {//����dfs���Թ�����
	int time = 1;
	int sz = 0;
	st[++sz] = mazestart;
	while (sz) {//DFS
		system("cls");
		cout << "�� " << time++ << " ��������\n";
		pair<int,int> top = st[sz];
		sz--;
		maze[top.first][top.second] = search_char;
		output(size);
		Sleep(cold_down);
		if (top == mazeend) {
			trace(size,time);
			return;
		}
		for (int i = 0; i < 4; i++) {
			if ((maze[top.first + dx[i]][top.second + dy[i]] == road_char || maze[top.first + dx[i]][top.second + dy[i]] == end_char)&&!access[top.first + dx[i]][top.second + dy[i]]) {
				fa[top.first + dx[i]][top.second + dy[i]] = top;
				access[top.first + dx[i]][top.second + dy[i]] = 1;
				st[++sz] = pair<int, int>(top.first + dx[i], top.second + dy[i]);
			}
		}
	}
	cout << "�޷��뿪�Թ���\n";
}
void mazeTraverse_bfs(int size) {//����bfs���Թ�����
	int head = 0, tail = 0, time = 1;
	qu[tail] = mazestart;
	while (head <= tail) {
		system("cls");
		cout << "�� " << time++ << " ��������\n";
		pair<int, int> top = qu[head];
		head++;
		output(size);
		Sleep(cold_down);
		if (top == mazeend) {
			trace(size, time);
			return;
		}
		for (int i = 0; i < 4; i++) {
			if ((maze[top.first + dx[i]][top.second + dy[i]] == road_char || maze[top.first + dx[i]][top.second + dy[i]] == end_char)&&!access[top.first + dx[i]][top.second + dy[i]]) {
				maze[top.first + dx[i]][top.second + dy[i]] = search_char;
				fa[top.first + dx[i]][top.second + dy[i]] = top;
				access[top.first + dx[i]][top.second + dy[i]] = 1;
				qu[++tail] = pair<int, int>(top.first + dx[i], top.second + dy[i]);
			}
		}
	}
}
void mazeTraverse_Astar(int size) {//����A*���Թ�����
	int time = 1;
	int sz = 0;
	heap[++sz] = Data(mazestart.first,mazestart.second);
	while (sz) {
		system("cls");
		cout << "�� " << time++ << " ��������\n";
		Data top = heap[1];
		pop(sz);
		maze[top.x][top.y] = search_char;
		output(size);
		if (pair<int,int>(top.x,top.y) == mazeend) {
			trace(size, time);
			return;
		}
		for (int i = 0; i < 4; i++) {
			if ((maze[top.x + dx[i]][top.y + dy[i]] == road_char || maze[top.x + dx[i]][top.y + dy[i]] == end_char)&&!access[top.x + dx[i]][top.y + dy[i]]) {
				fa[top.x + dx[i]][top.y + dy[i]] = pair<int,int>(top.x,top.y);
				access[top.x + dx[i]][top.y + dy[i]] = 1;
				inse(sz, Data(top.x + dx[i], top.y + dy[i]));
			}
		}
		Sleep(cold_down);
	}
	cout << "�޷��뿪�Թ���\n";
}
void mazeTraverse(int x,int y,int time,int size) {
	maze[x][y] = search_char;
	if (pair<int, int>(x, y) == mazeend) {
		trace(size, time);
		found = 1;
		return;
	}
	Sleep(cold_down);
	system("cls");
	cout << "�� " << time << " ��������\n";
	output(size);
	for (int i = 0; i < 4; i++) {
		if ((maze[x + dx[i]][y + dy[i]] == road_char || maze[x + dx[i]][y + dy[i]] == end_char)&&!access[x + dx[i]][y + dy[i]]) {
			fa[x + dx[i]][y + dy[i]] = pair<int, int>(x, y);
			access[x + dx[i]][y + dy[i]] = 1;
			mazeTraverse(x + dx[i], y + dy[i], time + 1, size);
			if (found)return;
		}
	}
}
void mazeTraverse_back(int x, int y, int time, int size) {
	maze[x][y] = search_char;
	if (pair<int, int>(x, y) == mazeend) {
		trace(size, time);
		found = 1;
		return;
	}
	Sleep(cold_down);
	system("cls");
	cout << "�� " << time << " ��������\n";
	output(size);
	for (int i = 0; i < 4; i++) {
		if ((maze[x + dx[i]][y + dy[i]] == road_char || maze[x + dx[i]][y + dy[i]] == end_char) && !access[x + dx[i]][y + dy[i]]) {
			fa[x + dx[i]][y + dy[i]] = pair<int, int>(x, y);
			access[x + dx[i]][y + dy[i]] = 1;
			mazeTraverse_back(x + dx[i], y + dy[i], time + 1, size);
			maze[x + dx[i]][y + dy[i]] = road_char;
			if (found)return;
		}
	}
}
int main() {
	cout << "\033[0m";
	system("cls");
	int t;
	int sel;
	cout << "�����������Թ��ķ�ʽ��\n1.Prim����Թ�\n2.������Թ�\n";
	cin >> sel;
	while (sel < 0 ||  sel > 2) {
		cout << "������Ч�����������룡\n";
		cin >> sel;
	}
	cout << "�������Թ��ĳߴ�(5-"<<MAXN<<")���ߴ�����������󻯴��ڣ�:\n";
	cin >> t;
	while (t < 5 || t > MAXN) {
		cout << "������Ч�����������룡\n";
		cin >> t;
	}
	switch (sel) {
	case 1: {
		mazeGenerator_Prim(t);
		break;
	}
	case 2: {
		int weight;
		cout << "������հ�·����Ȩ��(1-10):\n";
		cin >> weight;
		while (weight < 0 || weight>10) {
			cout << "������Ч�����������룡\n";
			cin >> weight;
		}
		mazeGenerator_Random(t,weight);
		break;
	}	
	}
	cout << "���������Թ�����\n";
	output(t);
	cout << "������ϣ�����������Թ��ķ�ʽ��\n1.DFS\n2.BFS\n3.A*\n4.�ݹ�\n5.���������\n";
	select_search:
	cin >> sel;
	switch (sel) {
	case 1: {
		mazeTraverse_dfs(t);
		break;
	}
	case 2: {
		mazeTraverse_bfs(t);
		break;
	}
	case 3: {
		mazeTraverse_Astar(t);
		break;
	}
	case 4: {
		mazeTraverse(mazestart.first, mazestart.second, 1, t);
		if (!found)cout << "�޷��뿪�Թ���\n";
		break;
	}
	case 5: {
		mazeTraverse_back(mazestart.first, mazestart.second, 1, t);
		if (!found)cout << "�޷��뿪�Թ���\n";
		break;
	}
	default: {
		cout << "��Ч��ѡ�����������룡\n";
		goto select_search;
	}
	}
	system("pause");
}