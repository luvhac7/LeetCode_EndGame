class Solution {
private:
    vector<int> parent{};
    int find(int i){
        if(parent[i]==-1)return i;
        return find(parent[i]);
    }
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        using tuple_t = typename std::tuple<int,int>;
        #define g0 std::get<0>
        #define g1 std::get<1>
        #define mt std::make_tuple
        const auto n{int(size(nums))};
        vector<tuple_t> a{};
        a.reserve(size(nums));
        int i{-1};
        ranges::transform(nums,back_inserter(a),[&](const auto x){
            return mt(x,++i);
        },{});
        ranges::sort(a);
        multiset<int> dq[100'001ull]{};
        parent.assign(n,-1);
        int j{g1(a[0])};
        for(int i{1};i<n;++i){
            if(g0(a[i])-g0(a[i-1]) <= limit){
                parent[g1(a[i])]=j;
            }
            else{
                j=g1(a[i]);
            }
        }
        if(0){
            ranges::copy(parent,ostream_iterator<int>(cout," "));
            cout<<"\n";
            return nums;
        }
        for(int i{};i<n;++i){
            dq[find(g1(a[i]))].emplace(g0(a[i]));
        }
        ranges::sort(a,[]<typename T>(const T& x,const T& y){
            return g1(x)<g1(y);
        });
        for(int i{};i<n;++i){
            auto&& set{dq[find(i)]};
            nums[i]=*ranges::begin(set);
            set.erase(begin(set));
        }
        return nums;
    }
};