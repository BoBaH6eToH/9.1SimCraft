#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

 class Item 
{
   public:
   string name;
   string slot;
   int itemLvl;
   string whereIs;
   int plusDps;
   bool raidItem;   
   
   void clr();
   void print();
   void cleanPrint();
   friend bool operator<(const Item &x, const Item &y) 
   {
      return x.plusDps < y.plusDps;
   }
};

void Item::clr()
{
   name.clear();
   whereIs.clear();
   slot.clear();
   itemLvl = plusDps = 0;
   raidItem = false;
}

void Item::print()
{
   cout << "Name:" << name << endl;
   cout << "Slot:" << slot << endl;
   cout << "WhereIs:" << whereIs << endl;
   cout << "PlusDps:" << plusDps << " ItemLvl:" << itemLvl << endl << endl;  
}

void Item::cleanPrint()
{
   cout << name << endl;
   cout << itemLvl << endl;
   cout << slot << endl;
   cout << whereIs << endl;
   cout << plusDps << endl;
   cout << endl;   
}

vector < pair < int, Item> > allItems;

int str2Int(const string &s)
{
   int val = 0;
   for (size_t i = 0; i < s.size(); i++)   
      val = val * 10 + static_cast<int>(s[i]-'0');
   return val;
   
}

void parseText()
{
   string s;
   Item it;
   while (getline(cin,s))
   {
      if (s.size() == 0 ) 
         continue;
      else if (s.size() > 1 && (s.substr(0,1) == "+" || s.substr(0,1) == "-"))
      {
         it.plusDps = str2Int(s.substr(1));
         allItems.push_back(make_pair(it.plusDps, it));
         it.clr();
      }
      else if (s.size() > 10)
      {
         if (s.find("variation hidden") != string::npos)
            continue;
         if (it.name.empty())
            it.name = s;
         else if (it.whereIs.empty())
            it.whereIs = s;
      }
      else if (s.size() <= 10)
      {
         if (isdigit(s[0]))
         {
            if (s.size() > 2 && (s.substr(0,3) == "252" || s.substr(0,3) == "259"))
               it.itemLvl = str2Int(s.substr(0,3));
            else
               continue;
         }
         else if (isalpha(s[0]))
            it.slot = s;
      }
   }
}

void outPrio(int prio = 0)
{
   sort(allItems.begin(), allItems.end());
   if (prio == 1)
      for (auto it:allItems)   
         it.second.print();        
   else
      for (auto it:allItems)
         it.second.cleanPrint();
}  

void outBest() 
{
   Item it;
   it.plusDps = 0;
   vector < Item > v;
   it.slot = "Trinket 1"; v.push_back(it);
   it.slot = "Trinket 2"; v.push_back(it);
   it.slot = "Main Hand"; v.push_back(it);
   it.slot = "Legs"; v.push_back(it);
   it.slot = "Chest"; v.push_back(it);
   it.slot = "Off Hand"; v.push_back(it);
   it.slot = "Shoulder"; v.push_back(it);
   it.slot = "Hands"; v.push_back(it);
   it.slot = "Neck"; v.push_back(it);
   it.slot = "Wrist"; v.push_back(it);
   it.slot = "Feet"; v.push_back(it);
   it.slot = "Back"; v.push_back(it);
   it.slot = "Waist"; v.push_back(it);
   it.slot = "Finger 1"; v.push_back(it);
   it.slot = "Finger 2"; v.push_back(it);

   for (int i = 0; i < allItems.size(); i++)
   {
      for (int j = 0; j < v.size(); j++)
      {
         if (allItems[i].second.slot == v[j].slot && allItems[i].second.plusDps > v[j].plusDps)
            v[j] = allItems[i].second;
      }
   }

   for (auto it : v)
      it.print();

}

int main()
{

   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   parseText();     

   //cout << "AllItems.size() =" << allItems.size() << endl;

   outPrio();

   //outBest();

   return 0;
}