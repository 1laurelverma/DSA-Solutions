class Solution {
public:
    bool exist(vector<vector<char>>& a, string word) {
		int n=a.size();
		int m=a[0].size();
		function<bool(int,int,string,int)> dfs=[&](int x,int y,string word,int ptr){
			if(ptr==word.length()) return true;
			if(x>=n||y>=m||x<0||y<0||a[x][y]=='1'||a[x][y]!=word[ptr]) return false;
			char ch=a[x][y];
			a[x][y]='1';
			bool res=dfs(x+1,y,word,ptr+1)||
				dfs(x-1,y,word,ptr+1)||
				dfs(x,y+1,word,ptr+1)||
				dfs(x,y-1,word,ptr+1);
			a[x][y]=ch;
			return res;
		};
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(word[0]==a[i][j] &&dfs(i,j,word,0)) return true;
			}
		}
		return false;
	}
};