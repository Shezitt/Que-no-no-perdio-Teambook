#define LOG(x) 63-__builtin_clzint(x)
class sparse_table{
    public:
    std::vector<std::vector<int>>st;
    std::vector<int>a;
    sparse_table(int n){
        st.resize(25,std::vector<int>(n));
    }
    void buildst_min();
    void buildst_max();
    void buildst_sum();
    int range_min_query(int l,int r);
    int range_max_query(int l,int r);
    int range_sum_query(int l,int r);
};
void sparse_table::buildst_max(){
    int n=a.size();
    f(i,0,n){
        st[0][i]=a[i];
    }
    f(i,1,25){
        for(int j=0;j+(1<<(i-1))<n;j++){
            st[i][j]=std::max(st[i-1][j],st[i-1][j+(1<<(i-1))]);
        }
    }
}
void sparse_table::buildst_min(){
    int n=a.size();
    f(i,0,n){ // for i = 0...n-1
        st[0][i]=a[i];
    }
    f(i,1,25){
        for(int j=0;j+(1<<(i-1))<n;j++){
            st[i][j]=std::min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
        }
    }
}
void sparse_table::buildst_sum(){
    int n=a.size();
    f(i,0,n){
        st[0][i]=a[i];
    }
    f(i,1,25){
        for(int j=0;j+(1<<(i-1))<n;j++){
            st[i][j]=st[i-1][j]+st[i-1][j+(1<<(i-1))];
        }
    }
}
int sparse_table::range_max_query(int l,int r){
     return std::max(st[int(LOG(r-l+1))][l],st[int(LOG(r-l+1))][r+1-(1<<int(LOG(r-l+1)))]);
}
int sparse_table::range_min_query(int l,int r){
    return std::min(st[int(LOG(r-l+1))][l],st[int(LOG(r-l+1))][r+1-(1<<int(LOG(r-l+1)))]);
}
int sparse_table::range_sum_query(int l,int r){
    std::vector<int> power_sum;
    int k=r-l+1;
    for(int i=25;i>=0&&k>0;i--){
        int power=int(pow(2,i));
        if(power<=k){
            power_sum.push_back(i);
            k-=power;
        }
    }
    int ans=0;
    int cur=0;
    for(auto x:power_sum){
        ans+=st[x][l+cur];
        cur+=int(pow(2,x));
    }
    return ans;
}