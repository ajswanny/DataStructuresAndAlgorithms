//
// Created by Alexander Swanson on 2/8/18.
//


/* Import Class declarations. */
#include "RedditElement.h"



// The default RedditElement constructor.
RedditElement::RedditElement() = default;


// A constructor for RedditElement that initializes every Class field using a vector.
RedditElement::RedditElement(vector<string> &input_vector) {

    // Define the object's fields.
    set_fields(input_vector);

}


// A method that provides the fields of the RedditElement object.
void RedditElement::info() {

    cout << "RedditElement Object: "    << get_id()             << endl

         << "\t Subreddit: "            << get_subreddit_name() << endl
         << "\t Upvotes: "              << get_ups()            << endl
         << "\t Downvotes: "            << get_downs()          << endl
         << "\t Score: "                << get_score()          << endl
         << "\t Category: "             << get_category()       << endl
         << "\t Date Created (UTC): "   << get_created_utc()    << endl

         << "\t Sentiment Score: "      << setprecision(12)
         << get_sentiment_score()       << endl

         << "\t Sentiment Magnitude: "  << setprecision(12)
         << get_sentiment_magnitude()

     << endl;

}


// A method that defines every field of the object.
void RedditElement::set_fields(vector<string> &input_vector) {

    // Define alphabetic values.
    set_id(input_vector[0]);
    set_subreddit_name(input_vector[1]);
    set_category(input_vector[5]);


    // Define numeric values.
    set_ups(integer_of(input_vector[2]));
    set_downs(integer_of(input_vector[3]));
    set_score(integer_of(input_vector[4]));
    set_created_utc(integer_of(input_vector[8]));

    set_sentiment_score(double_of(input_vector[6]));
    set_sentiment_magnitude(double_of(input_vector[7]));

}


// The function converts a valid string to a double and returns the value.
double RedditElement::double_of(string& str) {

    // Define an alias to size_type.
    string::size_type sz;


    // Define a converted double.
    double str_double = stod(str, &sz);


    return str_double;

}


// The function converts a valid string to a double and returns the value.
int RedditElement::integer_of(string& str) {

    // Define an alias to size_type.
    string::size_type sz;


    // Define a converted double.
    int str_integer = stoi(str, &sz);


    return str_integer;

}


// The getter and setter for 'created_utc'.
int RedditElement::get_created_utc() const {

    return this->created_utc;

}

void RedditElement::set_created_utc(int created_utc) {

    this->created_utc = created_utc;

}
//


// The getter and setter for 'ups'.
int RedditElement::get_ups() const {

    return this->ups;

}

void RedditElement::set_ups(int ups) {

    this->ups = ups;

}
//


// The getter and setter for 'downs'.
int RedditElement::get_downs() const {

    return this->downs;

}

void RedditElement::set_downs(int downs) {

    this->downs = downs;

}
//


// The getter and setter for 'score'.
int RedditElement::get_score() const {

    return this->score;

}

void RedditElement::set_score(int score) {

    this->score = score;

}
//


// The getter and setter for 'sentiment_score'.
double RedditElement::get_sentiment_score() const {

    return this->sentiment_score;

}

void RedditElement::set_sentiment_score(double sentiment_score) {

    this->sentiment_score = sentiment_score;

}
//


// The getter and setter for 'sentiment_magnitude'.
double RedditElement::get_sentiment_magnitude() const {

    return this->sentiment_magnitude;

}

void RedditElement::set_sentiment_magnitude(double sentiment_magnitude) {

    this->sentiment_magnitude = sentiment_magnitude;

}
//


// The getter and setter for 'id'.
const string &RedditElement::get_id() const {

    return this->id;

}

void RedditElement::set_id(const string &id) {

    this->id = id;

}
//


// The getter and setter for 'subreddit_name'.
const string &RedditElement::get_subreddit_name() const {

    return this->subreddit_name;

}

void RedditElement::set_subreddit_name(const string &subreddit_name) {

    this->subreddit_name = subreddit_name;

}
//


// The getter and setter for 'category'.
const string &RedditElement::get_category() const {

    return this->category;

}

void RedditElement::set_category(const string &category) {

    this->category = category;

}
