#include <bits/stdc++.h>
using namespace std;
/*
Data Structures Used:
  Queue using Doubly linked list for easy deletion
  Hash map to check whether the value present in the cache or not
*/
class LRU_cache
{
    int cache_size;
    /* Doubly linked list works as Queue*/
    list<int> dq;
    /* hash map to store the pointer of the page */
    map<int,list<int> :: iterator> mp;
  public:
      LRU_cache(int n)
      {
          cache_size=n;
      }
      /*----- Main CRUX of LRU -------*/
      void refer(int page)
      {
        if(mp.find(page)==mp.end())
        {
          if(dq.size()==cache_size)
          {
            int last=dq.back();
            dq.pop_back();
            mp.erase(last);
          }
        }
        else
        {
          dq.erase(mp[page]);
        }
        dq.push_front(page);
        mp[page]=dq.begin();
      }
      /*--------------------------------*/
      void display_cache()
      {
        list<int> :: iterator it;
        for(it=dq.begin();it!=dq.end();it++)
          cout<<*it<<" ";
        cout<<endl;
      }
};
int main()
{
  int cache_size;
  cin>>cache_size;
  LRU_cache lru(cache_size);
  int pages;
  cin>>pages;
  while(pages--)
  {
    int page;
    cin>>page;
    lru.refer(page);
  }
  lru.display_cache();
  return 0;
}
