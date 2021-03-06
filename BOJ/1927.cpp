#include <iostream>
using namespace std;
int heap[100001];
int lastIdx;
void pop() {
    if (lastIdx == 0){
        cout << 0 << '\n';
        return;
    }
    cout << heap[1] << '\n';
    swap(heap[1],heap[lastIdx]);
    lastIdx--;
    int now = 1;
    int child;
    do {
        child = 2*now;
        if (child+1 <= lastIdx && heap[child] > heap[child+1]) child++;
        if (child <= lastIdx && heap[now] > heap[child]){
            swap(heap[now],heap[child]);
        }
        now = child;
    } while( child <= lastIdx);
}
void push(int x) {
    heap[++lastIdx] = x;
    int now = lastIdx;
    do {
        if (heap[now/2] > heap[now]){
            swap(heap[now/2],heap[now]);
        } else break;
        now = now/2;
    }while (now > 1);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t,x;
    cin >> t;
    while (t--) {
        cin >> x;
        if (x){
            push(x);
        } else pop();
    }
    return 0;
}