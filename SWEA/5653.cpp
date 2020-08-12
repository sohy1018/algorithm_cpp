#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
#define MAX 350
#define BASE 150
typedef struct pos {
    int vital, x, y;
} POS;
int container[MAX][MAX];
const int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};//동서남북
int main(){
    int test_case, T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case){
        int N, M, K;
        queue <POS> q[11];
        int ans = 0;
        cin >> N >> M >> K;
        memset(container, 0, sizeof(container));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> container[i+BASE][j+BASE];
                if (container[i+BASE][j+BASE]) {
                    POS first;
                    first.vital = container[i + BASE][j + BASE]*2;
                    first.x = i + BASE, first.y = j + BASE;
                    q[container[i + BASE][j + BASE]].push(first);
                }
            }
        }//입력완료
        for (int i = 0; i <= K; i++) {
            for (int j = 10; j >= 1; j--) {
                int size = q[j].size();
                for (int k = 0; k < size; k++) {
                    auto x = q[j].front(); q[j].pop();
                    if (x.vital>j) {
                        if (container[x.x][x.y] > 0) {
                            ans++;
                            container[x.x][x.y] = -container[x.x][x.y];
                        }
                        q[j].push({ x.vital - 1,x.x,x.y });                        
                    }//비활성
                    else if (x.vital==j) {
                        q[j].push({ x.vital - 1,x.x,x.y });
                        for (int z = 0; z < 4; z++) {
                            int nx = x.x + dx[z];
                            int ny = x.y + dy[z];
                            if (container[nx][ny]) continue;
                            container[nx][ny] = j;
                            q[j].push({ x.vital * 2,nx,ny });
                        }
                    }//확장 + 활성
                    else if (x.vital < j && x.vital) {
                        q[j].push({ x.vital - 1,x.x,x.y });
                    }//확장 이후 활성
                    else { ans--; }//죽음
                }
            }
        }
        cout << "#" << test_case << ' ' << ans << '\n';
    }
    return 0;
}