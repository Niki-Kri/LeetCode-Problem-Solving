/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    vector<int> result;
    int index;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        index=0;
        vector<NestedInteger> stack = nestedList;
        int i=0;
        while (i<stack.size()){
            NestedInteger current = stack[i];
            if (current.isInteger()) {
                result.push_back(current.getInteger());
                i++;
            } else {
                vector<NestedInteger> subList = current.getList();
                stack.erase(stack.begin() + i);
                stack.insert(stack.begin() + i, subList.begin(), subList.end());
            }
        }
    }
    int next() {
        int val = result[index];
        index++;
        return val;
    }
    bool hasNext() {
        if (index < result.size()){
            return true;
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */