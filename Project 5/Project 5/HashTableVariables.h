//
// Created by Alexander Swanson on 4/16/18.
//

#ifndef PROJECT_5_HASHTABLEVARIABLES_H
#define PROJECT_5_HASHTABLEVARIABLES_H


#include "RedditElement.h"
#include "SeparateChaining.h"
#include "Probing.h"
#include "Operations.h"



// Declare Separate-Chaining Hash-Tables.
static SeparateChaining<RedditElement> SC_HashTable(10, get_reddit_element_id);
static SeparateChaining<RedditElement> SC_HT_SZ_002(2, get_reddit_element_id);
static SeparateChaining<RedditElement> SC_HT_SZ_127(127, get_reddit_element_id);
static SeparateChaining<RedditElement> SC_HT_SZ_233(233, get_reddit_element_id);
static SeparateChaining<RedditElement> SC_HT_SZ_353(353, get_reddit_element_id);
static SeparateChaining<RedditElement> SC_HT_SZ_419(419, get_reddit_element_id);

static SeparateChaining<RedditElement> alt_SC_HashTable(10, get_reddit_element_utc_creation);
static SeparateChaining<RedditElement> alt_SC_HT_SZ_002(2, get_reddit_element_utc_creation);
static SeparateChaining<RedditElement> alt_SC_HT_SZ_127(127, get_reddit_element_utc_creation);
static SeparateChaining<RedditElement> alt_SC_HT_SZ_233(233, get_reddit_element_utc_creation);
static SeparateChaining<RedditElement> alt_SC_HT_SZ_353(353, get_reddit_element_utc_creation);
static SeparateChaining<RedditElement> alt_SC_HT_SZ_419(419, get_reddit_element_utc_creation);


// Declare Linear-Probing Hash-Tables.
static Probing<RedditElement> LP_HashTable(10, get_reddit_element_id);
static Probing<RedditElement> LP_HT_SZ_002(2, get_reddit_element_id);
static Probing<RedditElement> LP_HT_SZ_127(127, get_reddit_element_id);
static Probing<RedditElement> LP_HT_SZ_233(233, get_reddit_element_id);
static Probing<RedditElement> LP_HT_SZ_353(353, get_reddit_element_id);
static Probing<RedditElement> LP_HT_SZ_419(419, get_reddit_element_id);

static Probing<RedditElement> alt_LP_HashTable(10, get_reddit_element_utc_creation);
static Probing<RedditElement> alt_LP_HT_SZ_002(2, get_reddit_element_utc_creation);
static Probing<RedditElement> alt_LP_HT_SZ_127(127, get_reddit_element_utc_creation);
static Probing<RedditElement> alt_LP_HT_SZ_233(233, get_reddit_element_utc_creation);
static Probing<RedditElement> alt_LP_HT_SZ_353(353, get_reddit_element_utc_creation);
static Probing<RedditElement> alt_LP_HT_SZ_419(419, get_reddit_element_utc_creation);




#endif //PROJECT_5_HASHTABLEVARIABLES_H
