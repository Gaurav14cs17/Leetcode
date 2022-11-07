// https://leetcode.com/problems/count-servers-that-communicate/description/

class Union_find{
    vector<int>parents;
    vector<int>ranks;
public:
    Union_find( int size ){
        parents.resize(size);
        ranks.resize(size , 1);
        iota(parents.begin() , parents.end() , 0);
    }

    int get_find(int node ){
        if( node == parents[node]){
            return node;
        }
        return parents[node] = get_find(parents[node]);
    }

    void merge( int node_x , int node_y){
        node_x = get_find(node_x);
        node_y = get_find(node_y);
        if(node_x ==  node_y )
            return;
        if(ranks[node_x] >  ranks[node_y]){
            parents[node_y] = node_x;
            ranks[node_x] += ranks[node_y];
            ranks[node_y] = 1;
        }
        else{
            parents[node_x] = node_y;
            ranks[node_y] += ranks[node_x];
             ranks[node_x] = 1;
        } 
    }

    int is_equal( int node_x , int node_y ){
        return (get_find(node_x) ==  get_find(node_y));
    }
    int get_ranks(int node ){
        return ranks[node];
    }
};


class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        auto points = [m](int i , int j ){
            return m*i +  j;
        };

        Union_find uf(n*m + 1 );
        map<int , vector<int>>rows , cols ;

        for( int i = 0  ; i<n ; ++i ){
            for( int j = 0  ; j<m ; ++j ){
                if(grid[i][j]){
                    int node = points(i , j );
                    rows[i].push_back(node);
                    cols[j].push_back(node);
                }
            }
        }

        for(const auto&[ node , val ] :  rows ){
            for( int i = 1 ; i<val.size() ; ++i ){
                uf.merge(val[i] , val[i-1]);
            }
        }

        for(const auto&[node , val ] :  cols ){
            for( int i =  1 ; i<val.size() ; ++i ){
                uf.merge(val[i] , val[i-1]);
            }
        }

        int sm =  0;
        for( int i = 0  ; i<m*n ; ++i ){
            //cout<<i<<" "<<uf.get_ranks(i)<<"\n";
            int rnk = uf.get_ranks(i);
            if(rnk > 1)
                sm +=  rnk;
        }
        return sm;
    }
};
