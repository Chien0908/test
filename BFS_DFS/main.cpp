#include <vector>
#include <iostream>
#include <cstring> 
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> adj(1001); 
bool visited[1001];

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);// nếu là đồ thị có hướng thì bỏ
    }
    memset(visited, false, sizeof(visited));
}

void DFS(int u) {
    cout << u << " "; // in đỉnh ra
    visited[u] = true;//đánh dấu đã thăm
    for (int v : adj[u]) {//duyệt các đỉnh kề với u mà chưa đc thăm
        
        if (!visited[v]) {//nếu chưa đc thăm
            DFS(v);//đệ quy
        }
    }
}
void BFS(int u) {
    queue<int> q; // khởi tạo hàng đợi
    q.push(u); //đưa u vào hàng đợi
    visited[u] = true;//đánh dấu u đã đc thăm
    while (!q.empty()) //kiểm tra hàng đợi nếu không rỗng
    {
        int v = q.front(); // lấy đỉnh ra hàng đợt
        q.pop();// xóa đỉnh hàng đợi 
        cout << v << " "; // in đỉnh ra
        for (int x : adj[v]) { //duyệt các đỉnh kề với v mà chưa đc thăm
            if (!visited[x]) { //nếu chưa đc thăm
                q.push(x); //thêm vào hàng đợi
                visited[x] = true;//đánh dấu đã thăm
            }
        }
    }
}
int main() {
    cout << "DFS: 1" << endl;
    cout << "BFS: 2" << endl;
    cin >> n;
    try {
        if (n == 1) {
            system("cls");
            cout << "Moi nhap danh sach canh:" << endl;
            input();
            DFS(1);
            cout << endl << "DFS" << endl;
        }
        else if (n == 2) {
            system("cls");
            cout << "Moi nhap danh sach canh:" << endl;
            input();
            BFS(1);
            cout << endl << "BFS" << endl;
        }
        else {
            throw "Invalid input."; 
        }
    }
    catch (const char* msg) {
        cerr << "Error: " << msg << endl;
    }
    
    return 0;
}
//// danh sách  cạnh
//9 9
//1 2
//1 3
//1 5
//2 4
//3 6
//3 7
//3 9
//5 8
//8 9