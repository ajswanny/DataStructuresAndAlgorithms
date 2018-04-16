//
// Created by Admin on 4/16/18.
//

#ifndef PROJECT_5_HASHTABLEVARIABLES_H
#define PROJECT_5_HASHTABLEVARIABLES_H


#include "RedditElement.h"
#include "SeparateChaining.h"
#include "Probing.h"
#include "Operations.h"



// Declare Separate-Chaining Hash-Tables.
static SeparateChaining<RedditElement> SC_HashTable(10, get_reddit_element_key);
static SeparateChaining<RedditElement> SC_HT_SZ_002(2, get_reddit_element_key);
static SeparateChaining<RedditElement> SC_HT_SZ_127(127, get_reddit_element_key);
static SeparateChaining<RedditElement> SC_HT_SZ_233(233, get_reddit_element_key);
static SeparateChaining<RedditElement> SC_HT_SZ_353(353, get_reddit_element_key);
static SeparateChaining<RedditElement> SC_HT_SZ_419(419, get_reddit_element_key);


// Declare Linear-Probing Hash-Tables.
static Probing<RedditElement> LP_HashTable(10, get_reddit_element_key);
static Probing<RedditElement> LP_HT_SZ_002(2, get_reddit_element_key);
static Probing<RedditElement> LP_HT_SZ_127(127, get_reddit_element_key);
static Probing<RedditElement> LP_HT_SZ_233(233, get_reddit_element_key);
static Probing<RedditElement> LP_HT_SZ_353(353, get_reddit_element_key);
static Probing<RedditElement> LP_HT_SZ_419(419, get_reddit_element_key);




#endif //PROJECT_5_HASHTABLEVARIABLES_H
