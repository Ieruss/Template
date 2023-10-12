inline void bfs(vector<int> &d, int x){
	d[x] = 0;
	queue< pair<int , int> >q;
	q.push({x,d[x]});
	while(!q.empty()){
		pair<int,int> it = q.front();
		q.pop();
		for(int i : g[it.first]){
			if(d[i] > it.second + 1){
				d[i] = it.second + 1;
				q.push({i,d[i]});
			}
		}
	}
}
