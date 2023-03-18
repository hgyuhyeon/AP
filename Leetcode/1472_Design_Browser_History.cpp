class BrowserHistory {
public:
    int index;
    vector<string> pages;

    BrowserHistory(string homepage) {
        pages.clear();
        pages.push_back(homepage);
        index = 0;
    }
    
    void visit(string url) {
        while (index != pages.size() - 1) pages.pop_back();
        pages.push_back(url);
        index++;
    }
    
    string back(int steps) {
        if (index - steps >= 0) index -= steps;
        else index = 0;
        return pages[index];
    }
    
    string forward(int steps) {
        if (index + steps < pages.size()) index += steps;
        else index = pages.size() - 1;
        return pages[index];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */