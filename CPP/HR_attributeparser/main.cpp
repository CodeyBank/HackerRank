#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <assert.h>
#include <fstream>
#include <map>
#include <string>

#define USE_TEST_FILE 1

using namespace std;

typedef struct TagClass
{
    string tag_name;
    map<string, string> atrribute_value_pairs;
    vector<string> child_tags;
    bool hasChild(const string &new_tag)
    {
        // use this to check if tag has child with given name by searching through the children
        for (auto &t : children)
            if (t.tag_name == new_tag)
                return true;
        return false;
    }
    vector<TagClass> children;
    bool completelyDefined{false};
} Tag;

vector<Tag> Tags;

Tag *checkCompleteness(Tag *tag);

Tag *parseSource(string line);

Tag *getTag(vector<Tag> &tag_list, string tag_name);

void parseQuery(string Line);

void storeTag(vector<Tag> &tagList, Tag *tagToAdd);

bool containsTag(const string tagname);

string findAttributeValue(const Tag &tag, const string &attribute);

Tag *recursiveSearch(Tag *parentTag, string tagname);

int main()
{

    string line;
    int N, Q;
    Tag *ret = nullptr;

#if USE_TEST_FILE
    // test file name
    string file_name = "testcases.txt";

    // attach an input stream to the file
    ifstream input_stream(file_name);

    // check stream status
    if (!input_stream)
    {
        cerr << "Can't open input file! \n";
        return 1;
    }
    getline(input_stream, line);
    stringstream ss(line);
    ss >> N >> Q;
#else
    cin >> N >> Q;
    cin.ignore();
#endif // USE_TEST_FILE

    vector<string> HRML_lines, Queries;

    int i{0};
    // read at all the lines and store accordingly
    while (i < (Q + N))
    {
        // save the source first
        if (i < N)
        {
#if USE_TEST_FILE
            getline(input_stream, line);
#else
            getline(cin, line);
#endif
            if (!line.empty()) HRML_lines.push_back(line);
        }
        else
        {
#if USE_TEST_FILE
            getline(input_stream, line);
#else
            getline(cin, line);
#endif
            if (!line.empty()) Queries.push_back(line);
        }
        i++;
    }

    int n = 0;
    do
    {
        ret = parseSource(HRML_lines.at(n));
        // only store if nut null
        if (ret != nullptr)
        {
            storeTag(Tags, ret);
        }
        n++;

    } while (n < N);

    int q = 0;
    do
    {
        parseQuery(Queries.at(q));
        q++;

    } while (q < Q);

    return 0;
}

Tag *parseSource(string line)
{

    // create a copy of the string and strip the beginning < and >
    string tempLine = line;
    if (tempLine.size() > 1)
    {
        tempLine.erase(0, 1);
        tempLine.pop_back();
    }
    else
    {
        Tag *failed = nullptr;
        return failed;
    }

    stringstream ss(tempLine);
    string str = "</";

    bool flag{false};
    vector<string> att_name, att_value;
    Tag *emptyTag = nullptr;

    // check if it is an opening or closing tag and update corresponding tag
    if ((line.find(str)) == !string::npos)
    {
        // check the name of the tage

        string tagname;
        ss >> tagname;
        tagname.erase(0, 1); // remove the / character

        if (Tags.size() > 0)
        {
            //            cout<<"Searching for tagname "<<tagname<<endl;

            Tag *val;
            for (auto &parent : Tags)
            {
                val = recursiveSearch(&parent, tagname);
                if (val != nullptr)
                {
                    val->completelyDefined = true;
                    break;
                }
            }
        }
    }
    else
    {
        Tag *new_tag = new Tag;
        ss >> new_tag->tag_name;

        // read everything in the stream one by one and ignore the =
        string value;
        while (ss >> value)
        {

            if ((value == "="))
            {
                flag = true;
                continue;
            }

            if (!flag)
                att_name.push_back(value);
            else
                att_value.push_back(value);
            flag = false;
        }

        //        cout<<"attr count:"<<att_name.size()<<" value count:"<<att_value.size()<<endl;

        assert(att_name.size() == att_value.size());

        // save all the tags in the map
        // clean the values and remove extra quotes
        for (string &val : att_value)
        {
            val.erase(0, 1);
            val.erase(val.length() - 1);
        }

        for (size_t j{0}; j < att_name.size(); j++)
        {
            new_tag->atrribute_value_pairs.insert(make_pair(att_name.at(j), att_value.at(j)));
        }
        return new_tag;
    }

    return emptyTag;
}

void parseQuery(string Line)
{

    size_t pos_tilda = 0;
    char dot{'.'};
    string tilda{"~"};

    // find index of tilda
    pos_tilda = Line.find(tilda);
    string attribute_id;
    // extract the attribute identifier
    if (pos_tilda != string::npos)
    {
        attribute_id = Line.substr(pos_tilda + 1);
        Line.erase(pos_tilda);
    }

    // extract the tags
    size_t previous_index = 0;
    vector<string> list_of_tags;
    string token;

    while ((previous_index = Line.find(dot)) != std::string::npos)
    {
        token = Line.substr(0, previous_index);
        list_of_tags.push_back(token);
        Line.erase(0, previous_index + 1);
    }
    // at this point there is remaining only one tag. save it to taglist
    list_of_tags.push_back(Line);

    // search for the parent tag in the tree
    Tag *val;
    for (auto &parent : Tags)
    {
        val = recursiveSearch(&parent, list_of_tags.at(0));
        if (val != nullptr)
            break;
    }
    if (val == nullptr)
    {
        cout << "Not Found!" << endl;
        return;
    }

    if (list_of_tags.size() == 1)
    {
        // here we have only one tag and no kids to be searched forit
        // if ((val != nullptr))
        // {
            cout << findAttributeValue(*val, attribute_id) << endl;
        // }
        // else
        //     cout << "Not Found!\n";
        // return;
    }
    else if (list_of_tags.size() > 1)
    {
        // we are dealing with a much tougher situation return pointer to the last tag in the list if Found

        // for (auto &t:)

        for (size_t i{0}; i < list_of_tags.size()-1; i++)
        {
            string current_tag = list_of_tags.at(i+1);
            Tag *newTag = recursiveSearch(val, current_tag);
            if (newTag != nullptr)
            {
                val = newTag;
            }
            else
            {
                cout << "Not Found!\n";
                return;
            }
        }

        cout << findAttributeValue(*val, attribute_id) << endl;
    }
}

Tag *getTag(vector<Tag> &tag_list, string tag_name)
{
    Tag *retval = nullptr;
    for (auto it = tag_list.begin(); it != tag_list.end(); it++)
    {
        if (it->tag_name == tag_name)
        {
            // return the value
            return &(*it);
        }
    }
    return retval;
}

Tag *recursiveSearch(Tag *parentTag, string tagname)
{
    Tag *emptyTag = nullptr;
    if (parentTag->tag_name == tagname)
    {
        emptyTag = parentTag;
        return emptyTag;
    }
    for (auto &child : parentTag->children)
    {
        emptyTag = recursiveSearch(&child, tagname);
        if (emptyTag != nullptr)
        {
            return emptyTag;
        }
    }
    return emptyTag;
}

string findAttributeValue(const Tag &tag, const string &attribute)
{

    string retval{"Not Found!"};
    for (auto it = tag.atrribute_value_pairs.begin(); it != tag.atrribute_value_pairs.end(); it++)
    {
        if (it->first == attribute)
            return it->second;
    }
    return retval;
}

bool containsTag(const string tagname)
{
    for (auto &v : Tags)
    {
        if (v.tag_name == tagname)
        {
            return true;
        }
    }
    return false;
}

void storeTag(vector<Tag> &tagList, Tag *tagToAdd)
{
    for (auto it = tagList.rbegin(); it != tagList.rend(); ++it)
    {
        if (it->completelyDefined)
            continue;
        else
        {
            // check if any children are not completely defined
            Tag *openChild = checkCompleteness(&(*it));
            if(openChild !=nullptr) {
                openChild->children.push_back(*tagToAdd);
                return;
            }

        }
    }

    tagList.push_back(*tagToAdd);
}

Tag *checkCompleteness(Tag *tag)
{
    Tag *emptyTag = nullptr;
    if (tag->children.empty() && !tag->completelyDefined)
        return tag;
    for (auto &t : tag->children)
    {
        emptyTag = checkCompleteness(&t);
        // if (emptyTag != nullptr)
        //     break;
    }
    return emptyTag;
}
