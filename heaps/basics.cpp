#include <bits/stdc++.h>
using namespace std;
int size=0;
int capacity=10;
vector<int> items(capacity);

/* Prebuilt Functions */

int get_left_child_index(int Parent) { return 2*Parent+1; }
int get_right_child_index(int Parent) { return 2*Parent+2; }
int get_parent_index(int child) { return (child-1)/2; }

bool has_left_child(int index) { return get_left_child_index(index)<size; }
bool has_right_child(int index) { return get_right_child_index(index)<size; }
bool has_parent(int index) { return get_parent_index(index)<size; }

int left_child(int index) { return items[get_left_child_index(index)]; }
int right_child(int index) { return items[get_right_child_index(index)]; }
int parent(int index) { return items[get_parent_index(index)]; }

void swap(int i,int j)
{
  int temp=items[i];
  items[i]=items[j];
  items[j]=temp;
}

void ensure_extra_copy()
{
  if(size==capacity)
  {
    capacity=capacity*2;
    items.resize(capacity*2);
  }
}

/*-------------------------MIN HEAP---------------------------*/

void heapifyUp()
{
  int index=size-1;
  while(has_parent(index)&&parent(index)>items[index])
  {
    swap(get_parent_index(index),index);
    index=get_parent_index(index);
  }
}

void heapifyDown()
{
  int index=0;
  while(has_left_child(index))
  {
    int smaller_child_index=get_left_child_index(index);
    if(has_right_child(index)&&left_child(index)>right_child(index))
    {
      smaller_child_index=get_right_child_index(index);
    }
    if(items[index]<items[smaller_child_index])
      break;
    else
      swap(index,smaller_child_index);
    index=smaller_child_index;
  }
}

/* Peeking and Popping and Adding Operations */
int peek()
{
  try
  {
    if(size==0)
    {
      throw size;
    }
    return items[0];
  }
  catch(int size)
  {
    cout<<"[INFO] Caught size "<<size<<endl;
  }
  return 0;
}

int pop()
{
  try
  {
    if(size==0)
    {
      throw size;
    }
    int item=items[0];
    items[0]=items[size-1];
    size--;
    heapifyDown();
    return item;
  }
  catch(int size)
  {
    cout<<"[INFO] Caught size "<<size<<endl;
  }
  return 0;
}

void add(int val)
{
  ensure_extra_copy();
  items[size]=val;
  size++;
  heapifyUp();
}

int main()
{
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    int val;
    cin>>val;
    add(val);
    cout<<peek()<<endl;
  }
}
