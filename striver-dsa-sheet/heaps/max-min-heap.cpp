void heapify(vector<int> &heap, int k, int &size) {
    int l = (2 * k) + 1;
    int r = (2 * k) + 2;
    int smallest = k;

    if (l < size && heap[l] < heap[k]) {
        smallest = l;
    }
    if (r < size && heap[r] < heap[smallest]) {
        smallest = r;
    }
    if (smallest != k) {
        int temp = heap[k];
        heap[k] = heap[smallest];
        heap[smallest] = temp;
        heapify(heap, smallest, size);
    }
}

int getMin(vector<int> &heap, int &size) {
    if (size == 1) {
        size -= 1;
        return heap[0];
    }

    int ans = heap[0];

    heap[0] = heap[size - 1];
    size--;

    heapify(heap, 0, size);

    return ans;
}

void insert(vector<int> &heap, int val, int &size) {
    heap[size] = val;

    int i = size;
    size++;

    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    int size = 0;

    vector<int> heap(n);
    vector<int> ans;

    for(int i=0;i<n;i++){
        if(q[i][0] == 0){
            insert(heap, q[i][1], size);
        }else{
            ans.push_back(getMin(heap, size));
        }
    }

    return ans;
}
