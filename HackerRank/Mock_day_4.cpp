int truckTour(vector<vector<int>> petrolpumps) { 
    int p = 0, idx = 1;
    for (int i = 0; i < petrolpumps.size(); i++) {
        p += petrolpumps[i][0];
        if (p - petrolpumps[i][1] >= 0) p -= petrolpumps[i][1];
        else {
            p = 0;
            idx = i+1;
        }
    }
    return idx;
}