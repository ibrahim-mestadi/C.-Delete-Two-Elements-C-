#include <bits/stdc++.h>

using namespace std;


int main() {
   int t ; 
   cin >> t ; 
   while(t--) {
      int n ; 
      cin >> n ;
      vector<int> a(n) ; 
      map <int,int> cnt ; 
      for(int i = 0; i < n ; i++) {
         cin >> a[i] ; 
      }
      for (auto x : a) {
         cnt[x] += 1 ; 
      }

     /* for (auto x : cnt) {
         cout << x.first << " : " << x.second << endl ;  
      }*/

      long long sum = accumulate(a.begin(), a.end(),0LL) ;

      if( (2 *sum ) % n != 0 ) {
         cout << 0 << endl ;
         continue ;
      }

      long long S = (2*sum) /n ; 
      long long rep = 0 ; 
      for(int i = 0 ; i < n ; i++) {
         if(cnt.count(S-a[i])) {
            rep += cnt[S-a[i]] ;
         }
         if(S-a[i] == a[i]) {
            rep -- ; 
         }
      }

      cout << rep / 2 << endl ; 


   }
   return 0 ; 
  
}
