#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <cassert>
#include <regex>

using namespace std;

int main()
{
    std::set<std::string> ins_list;
    //Opening input file
    //ifstream input_file("Instruction.def", ios::in);
    //ifstream input_file("test.def", ios::in);
    ifstream input_file("Instruction.def", ios::in);
    assert(input_file.is_open() && "ERROR: Couldn't open Graph.def file");

    //Reading comments

    //Defining comment regex
    regex reg_start_comment("^/\\*.*$");
    regex reg_end_comment("^.*\\*/$");
    regex reg_whole_comment("/\\*(?:.|[\\n\\r])*?\\*/");
    regex reg_single_comment("^//.*$");

    //start reading
    regex reg_param_start("^param.*$");
    //regex reg_start_line("^\\s*.*\\s*\\(\\d+,\\s.* , .*\\)");
    regex reg_start_line("^\\s*.*\\s*\\(\\s*\\d+,\\s*(.*)\\s*,\\s*.*\\).*$");
    regex reg_empty_line("^\\s*$");
    regex reg_capture_param("^.*?\\<(.*),");
    //regex reg_capture_value("^.*?\\<.*,\\s*(.*)\\>");
    regex reg_capture_value("^.*?\\<.*,\\s*(\\d+)\\>");

    smatch pattern_match;

    stringstream comment;

    for( string line; getline(input_file, line); ){

        if(regex_search(line,pattern_match, reg_start_line))
            ins_list.emplace(pattern_match[1]);
            //cout << pattern_match[1] << endl;
        //else
            //cout << "Fail!" << endl;

        ////Checking for batch comment in single line
        //if(regex_match(line, reg_whole_comment))
        //    comment << line;
        ////Check for single line comment
        //else if(regex_match(line, reg_single_comment))
        //    comment << line;
        ////Check if commenting block has been finished 
        //else if(regex_match(line, reg_end_comment)){
        //    read_comment = false;
        //    comment << line;
        //    //cout << comment.str() << endl;
        //    comment.clear();
        //}
        ////Check to see if the commenting block has been started
        //else if(regex_match(line, reg_start_comment)){
        //    read_comment = true;
        //    comment << line;
        //}
        ////Continue reading comment
        //else if(read_comment)
        //    comment << endl << line;
        ////skip empty line
        //else if(regex_match(line, reg_empty_line))
        //    continue;
        //else{
        //    //Comment lines they have been finished
        //    //Check whether doc is in a right format
        //    assert(regex_match(line, reg_param_start) && "ERROR: PARAM FILE WRONG FORMAT");
        //    if(regex_search(line, pattern_match, reg_capture_param))
        //        cout << "Match: " << pattern_match[1] << endl;
        //    else
        //        assert(regex_match(line, reg_capture_param) && "ERROR: PARAM WRONG FORMAT");

        //    if(regex_search(line, pattern_match, reg_capture_value))
        //        cout << "Match: " << pattern_match[1] << endl;
        //    else
        //        assert(regex_match(line,reg_capture_value) && "ERROR: VALUE WRONG FORMAT (SHOULD BE DIGIT)");
        //}

    }

    for(auto &c: ins_list)
        cout << c << endl;
    return 0;
}
