#include <cstdio>
using namespace std;
int a[1002][1002];
int main(){
    int r,c,q,temp;
    scanf("%d %d %d", &r, &c, &q);
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            scanf("%d", &temp);
            a[i][j] = a[i-1][j] + a[i][j-1] -a[i-1][j-1]+ temp;
        }
    }
    int x1,y1,x2,y2;
    while(q--){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d\n", (a[x2][y2]-a[x1-1][y2]-a[x2][y1-1]+a[x1-1][y1-1])/((x2-x1+1)*(y2-y1+1)));
    }
    return 0;
}