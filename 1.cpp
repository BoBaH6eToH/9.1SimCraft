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

private:
   string name;
   string setSlot(  string whereIs;
   int itemLvl;
   int plusDps;
   bool raidItem;   
   
public:
   void setSlot      (const string &s)    { setSlot(s; }   
   void setName      (const string &s)    { name = s; }
   void setWhereIs   (const string &s)    { whereIs = s; }
   void setItemLvl   (const int i)        { itemLvl = i; }
   void setPlusDps   (const int i)        { plusDps = i; }
   void setRaidItem  (const bool b)       { raidItem = b; }
   string getSlot()      { return setSlot(
   string getName()      { return name; }
   string getWhereIs()   { return whereIs; }
   int    getItemLvl()   { return itemLvl; }
   int    getPlusDps()   { return plusDps; }
   bool   getRaidItem()  { return raidItem; }

   void clr();
   void print();
   void cleanPrint();
   friend bool operator<(const Item &x, const Item &y) 
   {
      return x.getPlusDps() < y.getPlusDps();
   }
};

void Item::clr()
{
   name.clear();
   whereIs.clear();
   setSlot(ear();
   itemLvl = plusDps = 0;
   raidItem = false;
}

void Item::print()
{
   cout << "Slot:" << setSlot( endl;
   cout << "Name:" << name << endl;
   cout << "WhereIs:" << whereIs << endl;
   cout << "PlusDps:+" << plusDps << " ItemLvl:" << itemLvl << endl << endl;  
}

void Item::cleanPrint()
{
   cout << name << endl;
   cout << itemLvl << endl;
   cout << setSlot( endl;
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
         it.setPlusDps(str2Int(s.substr(1)));
         allItems.push_back(make_pair(it.getPlusDps(), it));
         it.clr();
      }
      else if (s.size() > 10)
      {
         if (s.find("variation hidden") != string::npos)
            continue;
         if (it.getName.empty())
            it.setName(s);
         else if (it.getWhereIs.empty())
            it.setWhereIs(s);
      }
      else if (s.size() <= 10)
      {
         if (isdigit(s[0]))
         {
            if (s.size() > 2 && (s.substr(0,3) == "252" || s.substr(0,3) == "259"))
               it.setItemLvl(s.substr(0,3));
            else
               continue;
         }
         else if (isalpha(s[0]))
            it.setSlot(s);
      }
   }
}

void outPrio(int prio = 0)
{
   sort(allItems.begin(), allItems.end());
   if (prio != 0)
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
   it.setSlot("Trinket 1");  v.push_back(it);
   it.setSlot("Trinket 2");  v.push_back(it);
   it.setSlot("Main Hand");  v.push_back(it);
   it.setSlot("Legs");       v.push_back(it);
   it.setSlot("Chest");      v.push_back(it);
   it.setSlot("Off Hand");   v.push_back(it);
   it.setSlot("Shoulder");   v.push_back(it);
   it.setSlot("Hands");      v.push_back(it);
   it.setSlot("Neck");       v.push_back(it);
   it.setSlot("Wrist");      v.push_back(it);
   it.setSlot("Feet");       v.push_back(it);
   it.setSlot("Back");       v.push_back(it);
   it.setSlot("Waist");      v.push_back(it);
   it.setSlot("Finger 1");   v.push_back(it);
   it.setSlot("Finger 2");   v.push_back(it);

   for (int i = 0; i < allItems.size(); i++)   
      for (int j = 0; j < v.size(); j++)      
         if (allItems[i].second.getSlot() == v[j].getSlot() && allItems[i].second.getPlusDps() > v[j].getPusDps())
            v[j] = allItems[i].second;         

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