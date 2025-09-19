class Spreadsheet {
public:
    vector<vector<int>>grid;
    
    Spreadsheet(int rows) {
        grid.assign(rows,vector<int>(26,0));
    }

    void setCell(string cell,int value) {
        int col=cell[0]-'A';
        int row=stoi(cell.substr(1))-1;
        if (row>=0&& row<grid.size())grid[row][col]=value;
    }

    void resetCell(string cell) {
        int col=cell[0]-'A';
        int row=stoi(cell.substr(1)) - 1;
        if (row>=0 &&row<grid.size())grid[row][col]=0;
    }

    int getValue(string formula) {
        int sum=0,i=1;
        while (i<formula.size()) {
            string temp="";
            while (i<formula.size()&&formula[i]!='+') {
                temp+=formula[i];
                i++;
            }
            if (isdigit(temp[0]))sum +=stoi(temp);
            else {
                int col=temp[0]-'A';
                int row=stoi(temp.substr(1))- 1;
                if(row >=0&&row<grid.size())sum+=grid[row][col];
            }
            i++;
        }
        return sum;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */