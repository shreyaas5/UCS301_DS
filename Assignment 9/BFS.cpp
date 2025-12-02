void BFS(int i){
    int u;
    cout << i;
    visited[i] = 1;
    enqueue(q,i);
    while(!isEmpty(q)){
        u = dequeue(q);
        for(int v = 1; v <= n; v++){
            if (A[u][v] == 1 && visited[v] == 0){
                cout << v;
                visited[v] = 1;
                enqueue(q,v);
            }
        }
    }
}
