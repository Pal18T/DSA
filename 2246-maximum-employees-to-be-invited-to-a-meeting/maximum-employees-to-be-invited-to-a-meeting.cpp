const int mxN = 1e5;
class Solution {
public:
int inDeg[mxN];
    int ans[mxN];
    int sz[mxN];
    int un[mxN];
    
    int find(int a) {
        if (un[a] == a) return a;
        else return un[a] = find(un[a]);
    }
    void uni(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        //x has more, y has less
        sz[x] += sz[y];
        un[y] = un[x];
    }
    int maximumInvitations(vector<int>& adj) {
        int N = adj.size();
        
        for (int i = 0; i < N; ++i) {
            sz[i] = 1;
            un[i] = i;
            ans[i] = 1;
        }
        
        for (int i = 0; i < N; ++i) {
            inDeg[adj[i]]++;
        }
		//start of topo sort
        queue<int> st;
        for (int i = 0; i < N; ++i) {
            if (inDeg[i] == 0) {
                st.push(i);
            }
        }
        while (!st.empty()) {
            int v = st.front(); st.pop();
            int c = adj[v];
            ans[c] = max(ans[c], ans[v] + 1); //largest possible non-cyclic path up to node 'c'
            inDeg[c]--;
            if (inDeg[c] == 0) {
                st.push(c);
            }
        }
		//end of topo sort
		
		//figuring out the lengths of the cycles with disjoint structure
        for (int i = 0; i < N; ++i) {
            if (inDeg[i])
                uni(i, adj[i]);
        }

        int res = 0;
        int joinable = 0;
        for (int i = 0; i < N; ++i) {
            if (!inDeg[i]) continue; //we only care about the cyclic components
            int len = sz[find(i)]; //length of cycle for current node
            if (len == 2) {
				int neigh = adj[i];
                inDeg[neigh]--; //making sure we dont overcount in our "joinable" sum by revisiting neighbor
                len = ans[i] + ans[neigh]; //answer for cycle of length 2 is the sum of the largest paths up to the 2 nodes
                joinable += len;
            } else {
                //the only answer for a node with cycle of length >= 3 is just the length
				 res = max(res, len);
            }
        }
        
        return max(res, joinable);
    }
};