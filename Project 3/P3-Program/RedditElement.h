//
// Created by Admin on 2/26/18.
//

#ifndef P3_PROGRAM_REDDITELEMENT_H
#define P3_PROGRAM_REDDITELEMENT_H


/* Import necessary modules. */
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


using namespace std;


/**
 *
 */
class RedditElement {


private:
    /* Declare the Private Class fields. */

    /**
     *
     */
    int ups, downs, score, created_utc;

    /**
     *
     */
    double sentiment_score, sentiment_magnitude;

    /**
     *
     */
    string id, subreddit_name, category;


protected:
    /* Define the Protected Class methods. */

    /**
     *
     * @param index
     */
    void set_created_utc(int created_utc);


    /**
     *
     * @param ups
     */
    void set_ups(int ups);


    /**
     *
     * @param downs
     */
    void set_downs(int downs);


    /**
     *
     * @param score
     */
    void set_score(int score);


    /**
     *
     * @param sentiment_score
     */
    void set_sentiment_score(double sentiment_score);


    /**
     *
     * @param sentiment_magnitude
     */
    void set_sentiment_magnitude(double sentiment_magnitude);


    /**
     *
     * @param id
     */
    void set_id(const string &id);


    /**
     *
     * @param subreddit_name
     */
    void set_subreddit_name(const string &subreddit_name);


    /**
     *
     * @param category
     */
    void set_category(const string &category);


public:
    /* Define the Public Class methods. */

    /**
     *
     */
    RedditElement();


    /**
     *
     * @param input_vector
     */
    explicit RedditElement(vector<string>& input_vector);


    /**
     *
     */
    void info();


    /**
     *
     * @param input_vector
     */
    void set_fields(vector<string> &input_vector);


    /**
     * Converts a given String to a Double if given valid input.
     *
     * @param str
     * @return
     */
    double double_of(string& str);


    /**
     * Converts a given String to an Integer if given valid input.
     *
     * @param str
     * @return
     */
    int integer_of(string& str);


    /**
     *
     * @return
     */
    int get_created_utc() const;


    /**
     *
     * @return
     */
    int get_downs() const;


    /**
     *
     * @return
     */
    int get_ups() const;


    /**
     *
     * @return
     */
    int get_score() const;


    /**
     *
     * @return
     */
    double get_sentiment_score() const;


    /**
     *
     * @return
     */
    double get_sentiment_magnitude() const;


    /**
     *
     * @return
     */
    const string &get_id() const;


    /**
     *
     * @return
     */
    const string &get_subreddit_name() const;


    /**
     *
     * @return
     */
    const string &get_category() const;


};


#endif //PROJECT_2_REDDITDATA_H