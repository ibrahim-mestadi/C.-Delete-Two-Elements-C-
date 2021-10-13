# C.-Delete-Two-Elements
C++ Solution of the prombem "C. Delete Two Elements"

### Analyse the probleme : 

Clearly, the problem wants us to find the number of pairs to eliminate from an array, and the mean of the array stays the same.
Let say that the original array is  A = [a1,a2 . . . , an] and suppose that (ak,al) is a pair that satisfie the constraint. 
So  : </br>
  
             (a1 + a2 + . . . an) / n  = ((a1 + a2 + . . . an) - (ak + al))/(n-2) </br>
<=>                       nS   -  2S         =   nS - n ( ak + al )  </br>
<=>      ```diff              ak +al         =  2S/n  ```

#### The First Constraint we should remarque is : 

 ```diff  If 2*S / n is not an integer so the answer is 0 no pair will do the task ``` 
 ```cpp 
    if( (2 *sum ) % n != 0 ) {
         cout << 0 << endl ;
         continue ;
 ```

#### So if not the case : 
Now we will take a discussion :  The first ``` algprithm ``` we normally must see is making a loop inside loop to check all the possible pairs and increment a counter each time we find a positive answer. But it will be too slow because that algotihme is o(n²) and n can acheive  </br>   2 . 10^5. So can we do better ?

To increase Complexity let's first try to find a way to eliminate one loop at least. So if we change the look of our last equation that we find to : ``` ak = (2S/n) - al ``` 
the job will be easy if combine  it with a map (dictionnary in python ). We will create a map where we will store occurences of each element in the array, and we just have to find if 
```(2S/n) - al```  is in the array using the map and the answer will be the some of all this numbers.


#### Realy ?

No , acctually we forgot somthings : </br>
    ****if al = 2s/n it will be counted to times so here we should subtract 1*****
    ****and we will find pairs two times so we need to divide bt 2 at the end**** 

 ```cpp 
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
 ```

   
    
           
 
 
 
