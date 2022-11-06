//https://leetcode.com/problems/count-sub-islands/description/


class Union_find{
    vector<int>ranks;
    vector<int>parents;

public:
    
    Union_find( int size ){
        ranks.resize(size , 1);
        parents.resize(size);
        iota(parents.begin() , parents.end() , 0 );
    }

    int find( int node ){
        if(node == parents[node])
            return node;
        return  find(parents[node]);
    }

    void merge(int node_x , int node_y ){
        int x = find(node_x);
        int y = find(node_y);
        if(x == y )
            return ;
        if(ranks[x] >= ranks[y]){
            parents[y] = x;
            ranks[x] += ranks[y];
        }
        else{
            parents[x] = y;
            ranks[y] += ranks[x];
        }
    }

    bool is_connected( int x , int y ){
        return find(x) == find(y);
    }
};





class Solution {
public:



    Union_find build( vector<vector<int>>&grid ){
        int h = grid.size();
        int w = grid[0].size();

        Union_find uf(w*h);
        vector<vector<int>>dm = {{1,0},{0,1}};
        
        auto point = [w]( int i , int j ){
            return i*w + j;
        };

        for( int i = 0  ; i<h ; ++i ){
            for( int j = 0  ; j<w ; ++j ){
                if(grid[i][j]){
                    for( const auto&it : dm ){
                        int x = j + it[0];
                        int y = i + it[1];
                        if( x >= w || y >= h || !grid[ y ][ x ] )
                                continue;
                        uf.merge( point(i,j) , point(y,x));
                    }
                }
            }
        }
        return uf;
    }


    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {

        auto uf1 = build(grid1);
        auto uf2 = build(grid2);

        int h = grid2.size();
        int w = grid2[0].size();

        auto point = [w]( int i , int j ){
            return w*i + j;
        };  

        unordered_map<int , vector<pair<int , int >>>is_land2;
        for( int i = 0  ; i< h ; ++i ){
            for( int j = 0  ; j<w ; ++j ){
                if(grid2[i][j]){
                    int node = point(i,j);
                    is_land2[uf2.find(node)].push_back({i,j});
                }
            }
        }

        int cnt{0};

        for(const auto &[root , lands ] : is_land2 ){
            unordered_set<int>islands;
            bool is_water{false};
            for( const auto & coords : lands ){
                if(grid1[coords.first][coords.second]==0){
                    is_water = true;
                    break;
                }
                islands.insert(uf1.find(point(coords.first , coords.second )));
            }
            if(is_water == false && islands.size()==1)
                    cnt += 1;
        }

        return cnt;    
    }
};
