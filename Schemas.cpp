#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <math.h>
//#define int long long
using namespace std;
//typedef pair<string, string> pairs;

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    map<string, int> pos;
    map<string, tuple<string,string,string>> FKp; // PK, referenced table, FK
    vector<vector<string>> tables;
    while (true) {
        string command;
        cin >> command;
        if(command == "TABLE") {
            string parse; cin >> parse;
            string tablename = ""; int ind = 0;
            for(int i = ind; i < parse.size(); i++) {
                if (parse[i]=='(') {ind = i+1; break;}
                tablename+=parse[i];
            }
            vector<string> newtable;
            tables.push_back(newtable);
            pos[tablename]=tables.size()-1;
            string attribute = "";
            for(int i = ind; i < parse.size(); i++) {
                if(parse[i]==')') {tables[pos[tablename]].push_back(attribute); break;}
                if(parse[i]!=',') {attribute+=parse[i];}
                else {tables[pos[tablename]].push_back(attribute); attribute = "";}
            }
        } else if (command=="NRTABLE") {
            string parse; cin >> parse;
            int ind = 1; vector<string> t; vector<string> tt;
            string PK = ""; string FK = ""; string s = "";
            for(int i = ind; i < parse.size(); i++) {
                if(parse[i]==':') {t.push_back(s);PK=s;FK=s;ind=i+2;s="";break;}
                else if(parse[i]!=','){s+=parse[i];}
                else {t.push_back(s);s="";}
            }
            for(int i = ind; i < parse.size(); i++) {
                if(parse[i]=='}') {tt.push_back(s);break;}
                if(parse[i]!=',') {s+=parse[i];}
                else {tt.push_back(s);s="";}
            } tt.push_back(PK);
            cout << "Here is the relational schema" << endl;
            cout << "TABLE1{";
            for(int i = 0; i < t.size(); i++) {
                if(t[i]==FK) {cout << "FK(" << FK << ")";}
                else {cout << t[i];} if(i!=t.size()-1){cout<<",";}
            } cout << "}" << endl;
            cout << "TABLE2{";
            for(int i = 0; i < tt.size(); i++) {
                if(tt[i]==PK) {cout << "PK(" << PK << ")";}
                else {cout << tt[i];} if(i<tt.size()-1){cout<<",";}
            } cout << "}" << endl;
        }
        else if (command == "FOREIGN") {
            string parse; cin >> parse; int ind = 1;
            string FK = ""; string table = ""; string PK = ""; string rtable = "";
            for(int i = ind; i < parse.size(); i++) {
                if(parse[i]=='(') {ind = i+1; break;}
                table+=parse[i];
            }
            for(int i = ind; i < parse.size(); i++) {
                if(parse[i]==')') {break;}
                PK+=parse[i];
            } string empt; cin >> empt;
            string fparse; cin >> fparse; ind = 0;
            for(int i = 0; i < fparse.size(); i++) {
                if(fparse[i]=='(') {ind=i+1;break;}
                rtable+=fparse[i];
            }
            for(int i = ind; i < fparse.size(); i++) {
                if(fparse[i]==')') {break;}
                else {FK+=fparse[i];}
            }
            FKp[table]=make_tuple(PK,rtable,FK);
        } else if (command == "NRP") {
            cout << "The non-relational schema for this table is {";
            string table; cin >> table;
            if(FKp.count(table)) {
                for(int i = 0; i < tables[pos[table]].size(); i++) {
                    if(tables[pos[table]][i]!=get<0>(FKp[table])) {cout << tables[pos[table]][i] << ",";}
                } cout << get<0>(FKp[table]) << ":{";
                for(int i = 0; i < tables[pos[get<1>(FKp[table])]].size(); i++) {
                    string cur = tables[pos[get<1>(FKp[table])]][i];
                    if(cur!=get<2>(FKp[table])) {cout << cur; if(i!=tables[pos[get<1>(FKp[table])]].size()-1){cout << ',';}}
                }
                cout << "}}" << endl;
            }
        }
        else {cout << "Invalid Syntax" << endl;}
    }
    return 0;
}
