// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

class Union_find{
vector<int>parents;
vector<int>ranks;
public:
    int number_of_cycle = 0;
    int mx_rank_val = 0;
    set<int>st;
    int size;

    Union_find( int size ){
        this->size = size;
        parents.resize(size );
        ranks.resize(size , 1);
        iota(parents.begin() , parents.end() , 0 );
    }

    int find_parent( int node ){
        if(parents[node]==node)
            return node;
        return parents[node] = find_parent(parents[node]);
    }

    void merge( int node_x , int node_y){
        node_x = find_parent(node_x);
        node_y = find_parent(node_y);
        if(node_x == node_y ){
            number_of_cycle += 1;
            return;
        }
        if(ranks[node_x]>= ranks[node_y]){
            parents[node_y] = node_x;
            ranks[node_x] += ranks[node_y];
            mx_rank_val = max(mx_rank_val , ranks[node_x]);
        }
        else{
            parents[node_x] = node_y;
            ranks[node_y] += ranks[node_x];
            mx_rank_val = max(mx_rank_val , ranks[node_y]);
        }
    }

    int get_number_of_c(){
        for( int i =0 ; i<size-1 ; ++i ){
            st.insert(find_parent(i));
        }
        return st.size();
    }


};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int ans = 0 ;
        Union_find uf(n+1);

        for(auto it : connections ){
            int x = it[0];
            int y = it[1];
            uf.merge(x , y);
        }
        
        int c = uf.get_number_of_c();
        if((c-1) <= uf.number_of_cycle ){
            return c-1;
        }
        else
            return -1;
    }
};
