#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <regex>
#include <assert.h>
using namespace std;

typedef struct TagClass{
    string tag_name;
    map<string, string> atrribute_value_pairs;
    vector<string> child_tags;
    bool hasChild(const TagClass &new_tag){
        // use this to check if tag has child with given name by searching through the children
        for(TagClass &t :children)
            if(t.tag_name == new_tag.tag_name)
                return true;
        return false;
    }
    vector<TagClass> children;
    bool completelyDefined {false};
} Tag;

vector<Tag> Tags;

Tag *parseSource(const string line);

void storeTag(vector<Tag>&tagList, Tag *tagToAdd);

int main() {

    // retrieve N
//    int N, Q;
//    cin>>N>>Q;
//
//    for(int i{0}; i<=6; i++){
//        string line;
//        getline(cin, line);
//        Tag ret = parseSource(line);
////        storeTag(Tags,ret);
//    }
    string line;
    getline(cin, line);
    // declare map iterator
    map<string, string>::iterator iter;

    Tag *ret = parseSource(line);

    for (iter = ret->atrribute_value_pairs.begin(); iter != ret->atrribute_value_pairs.end(); ++iter) {
        cout << iter->first << " - " << iter->second << endl;
    }
    if(ret !=nullptr) storeTag(Tags,ret);

    getline(cin, line);
    ret = parseSource(line);


    for (iter = ret->atrribute_value_pairs.begin(); iter != ret->atrribute_value_pairs.end(); ++iter) {
        cout << iter->first << " - " << iter->second << endl;
    }
    if(ret !=nullptr) storeTag(Tags,ret);

    getline(cin, line);
    ret = parseSource(line);


    for (iter = ret->atrribute_value_pairs.begin(); iter != ret->atrribute_value_pairs.end(); ++iter) {
        cout << iter->first << " - " << iter->second << endl;
    }
    if(ret !=nullptr) storeTag(Tags,ret);

    getline(cin, line);
    ret = parseSource(line);


    // use iterator to display map elements
    for (iter = ret->atrribute_value_pairs.begin(); iter != ret->atrribute_value_pairs.end(); ++iter) {
        cout << iter->first << " - " << iter->second << endl;
    }
    if(ret !=nullptr) storeTag(Tags,ret);

    delete ret;
    return 0;
}


Tag *parseSource(const string line){

    // create a copy of the string and strip the beginning < and >
    string tempLine = line;
    tempLine.erase(0,1);
    tempLine.erase(tempLine.size()-1,1);


    stringstream ss(tempLine);
    string str="</";

    bool flag{false};
    vector<string> att_name, att_value;

    // check if it is an opening or closing tag and update corresponding tag
    if((line.find(str))==!string::npos){
        //check the name of the tage
        string tagname;
        ss>>tagname;
        tagname.erase(0,1);

        cout<<"Searching for tagname "<<tagname<<endl;
        for(Tag &v: Tags){
            if(v.tag_name == tagname){
                cout<<"found tag with name "<<tagname<<endl;
                v.completelyDefined = true;
            }
            else
                cout<<"could not find tag with name "<<tagname<<endl;
        }

    }

    else{
        Tag *new_tag = new Tag;
        ss>>new_tag->tag_name;

        // read everything in the stream one by one and ignore the =
        string value;
        while(ss>>value){

            if ((value == "=")){
                flag = true;
                continue;
            }

            if(!flag) att_name.push_back(value);
            else att_value.push_back(value);
            flag = false;
        }

        cout<<"attr count:"<<att_name.size()<<" value count:"<<att_value.size()<<endl;

        assert(att_name.size() == att_value.size());

        // save all the tags in the map
        for(size_t j{0}; j<att_name.size(); j++){
            new_tag->atrribute_value_pairs.insert(make_pair(att_name.at(j),att_value.at(j)));
        }
        return new_tag;
    }

    return (nullptr);;
}


void storeTag(vector<Tag>&tagList, Tag *tagToAdd){
        //add the newly created tag to the tag list

            // check if vector of Tags is empty? if yes create a fresh tag
    // if no, check if the defined tags are closed from last to first
    // if the tag is open, add new tag to open tag as child


    // check if there are any open tags
    for (auto it = tagList.rbegin(); it != tagList.rend(); ++it)
    {
        if (it->completelyDefined)
            continue;
        else{
            it->children.push_back(*tagToAdd);
            cout<<"Added new tag: "<<tagToAdd->tag_name<< " to "<<it->tag_name<<endl;
            return;
        }
    }

    tagList.push_back(*tagToAdd);
    cout<<"Added new tag: "<<tagToAdd->tag_name<< " to the list"<<endl;
    cout<<"There are currently "<<tagList.size()<< " tags in the list \n";
}
