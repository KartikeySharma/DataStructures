#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class HeapBuilder{
private:
    vector<int> data_;
    vector< pair<int, int> > swaps_;

    void WriteResponse() const{
        cout << swaps_.size() << "\n";
        for (int i = 0; i < swaps_.size(); ++i){
            cout << swaps_[i].first << " " << swaps_[i].second << "\n";
        }
    }

    void ReadData(){
        int n;
        cin >> n;
        data_.resize(n);
        for(int i = 0; i < n; ++i)
            cin >> data_[i];
    }

    void GenerateSwaps(){
        swaps_.clear();
        int n = data_.size();
        for(int i = n/2; i >= 0; i--){
            SiftDown(i);
        }
    }
    void SiftDown(int i){
        int minIndex = i;
        int l = LeftChild(i);
        if(l < data_.size() && data_[l] < data_[minIndex]){
            minIndex = l;
        }
        int r = RightChild(i);
        if(r < data_.size() && data_[r] < data_[minIndex]){
            minIndex = r;
        }
        if(i != minIndex){
            swap(data_[i], data_[minIndex]);
            swaps_.push_back(make_pair(i, minIndex));
            SiftDown(minIndex);
        }
    }
    int LeftChild(int i){
        if(i == 0)
            return i + 1;
        return 2*i + 1;
    }
    int RightChild(int i){
        if(i == 0)
            return i + 2;
        return 2*i + 2;
    }

public:
    void Solve()
    {
        ReadData();
        GenerateSwaps();
        WriteResponse();
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    HeapBuilder heap_builder;
    heap_builder.Solve();
    return 0;
}
