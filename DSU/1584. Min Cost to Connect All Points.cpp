// https://leetcode.com/problems/min-cost-to-connect-all-points/description/

struct Node{
    int f_idx ;
    int s_idx ;
    Node(int f_idx , int s_idx ){
        this->f_idx = f_idx;
        this->s_idx = s_idx;
    }
};

class Union_Find{

vector<int>parents;
vector<int>ranks;
public :
     Union_Find( int size ){
         parents.resize(size);
         ranks.resize(size ,  1 );
         iota(parents.begin() , parents.end() , 0 );
     }

     int find_parent(int node ){
         if(node == parents[node])
                return node;
         return parents[node] = find_parent(parents[node]);
     }

     void merge( int node_x , int node_y){
         node_x = find_parent(node_x);
         node_y = find_parent(node_y);
        if(node_x == node_y)
            return;
        if(ranks[node_x] >= ranks[node_y]){
            ranks[node_x] += ranks[node_y];
            parents[node_y] = node_x;
        }
        else{
            ranks[node_y] += ranks[node_x];
            parents[node_x] = node_y;
        }
     }

     bool is_equal(int node_x , int node_y ){
         return find_parent(node_x) == find_parent(node_y);
     }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
      auto add = [](int x , int y , int x1 , int y1 ){
                    return abs(x-x1) + abs(y-y1);
      };

      vector<pair<int , Node >>v;
      int n = points.size();
      for( int i = 0  ; i<n ; ++i ){
          for( int j = i + 1 ; j<n ; ++j ){
              int d = add(points[i][0] , points[i][1] , points[j][0] , points[j][1]);
              Node t(i,j);
              v.push_back({d , t});
          }
      }

      sort(v.begin() , v.end(), []( auto &left , auto &right ){
            return left.first < right.first ;
      });
    
      Union_Find uf(n*n);
      int sum = 0 ;
      for(auto it : v){
         int node_x = it.second.f_idx;
         int node_y = it.second.s_idx;
         if(! uf.is_equal(node_x , node_y)){
             sum += it.first;
             uf.merge(node_x , node_y);
             //cout<<it.first<<" ";
         }
      }
      return sum; 
    }
};
