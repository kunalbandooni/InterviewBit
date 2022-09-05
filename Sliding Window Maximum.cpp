vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    deque< pair<int, int> > window;
    for (int i = 0; i < A.size(); i++) {
        //piche se ssara chota wala remove karo taki sabse piche sabse bada
        while (!window.empty() && window.back().first <= A[i])  
            window.pop_back();
        window.push_back(make_pair(A[i], i));
        
        //samne se un elements ko hata do jo i pe khatm hone wale window me nahi hai
        while(window.front().second <= i - B)
            window.pop_front();
        if(i>=B-1)
        cout << (window.front().first) << ' ';
  }
  return {};
}
