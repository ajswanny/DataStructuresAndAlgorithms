//
// Created by Alexander Swanson.
//

#include "lecturer.h"
#include "Probing.h"
#include "SeparateChaining.h"
#include "RedditElement.h"
#include "Operations.h"
#include "HashTableVariables.h"


using namespace std;



/**
 *
 * @param data
 * @param verbose
 */
void work_separate_chaining_hts(vector<RedditElement> &data, bool verbose);


/**
 *
 * @param data
 * @param verbose
 */
void work_alt_separate_chaining_hts(vector<RedditElement> &data, bool verbose);



/**
 *
 * @param data
 */
void work_linear_probing_hts(vector<RedditElement> &data, bool verbose);


/**
 *
 * @param data
 * @param verbose
 */
void work_alt_linear_probing_hts(vector<RedditElement> &data, bool verbose);


int main() {

    // Define a container for RedditElement data.
    vector<RedditElement> reddit_element_data;


    // Populate the vector, having re-sized the data file beforehand to be composed of just 1000 entries.
    generate_reddit_data(false, reddit_element_data);

    // Define list of prime numbers to be used as Hash-Table initial sizes.
    vector<int> prime_numbers = {2, 127, 233, 353, 419};


    // Perform insertions for the Separate-Chaining Hash-Tables.
    work_separate_chaining_hts(reddit_element_data, true);

    // Perform insertions for the Linear-Probing Hash-Tables.
    work_linear_probing_hts(reddit_element_data, true);


    // Perform insertions for the Separate-Chaining Hash-Tables using a different Hash item key.
    work_alt_separate_chaining_hts(reddit_element_data, true);

    // Perform insertions for the Linear-Chaining Hash-Tables using a different Hash item key.
    work_alt_linear_probing_hts(reddit_element_data, true);


    return 0;

}


/**
 *
 * @param data
 */
void work_separate_chaining_hts(vector<RedditElement> &data, bool verbose) {

    /* Perform insertions. */
    // Table Size: 10
    int sc_ht_sz_010_reads = populate_sc_hash_table(data, SC_HashTable);

    // Table Size: 2
    int sc_ht_sz_002_reads = populate_sc_hash_table(data, SC_HT_SZ_002);

    // Table Size: 127
    int sc_ht_sz_127_reads = populate_sc_hash_table(data, SC_HT_SZ_127);

    // Table Size: 233
    int sc_ht_sz_233_reads = populate_sc_hash_table(data, SC_HT_SZ_233);

    // Table Size: 353
    int sc_ht_sz_353_reads = populate_sc_hash_table(data, SC_HT_SZ_353);

    // Table Size: 419
    int sc_ht_sz_419_reads = populate_sc_hash_table(data, SC_HT_SZ_419);


    // Define collection of insertion READS.
    vector<int> reads = {
            sc_ht_sz_010_reads,
            sc_ht_sz_002_reads,
            sc_ht_sz_127_reads,
            sc_ht_sz_233_reads,
            sc_ht_sz_353_reads,
            sc_ht_sz_419_reads
    };


    // Output READS data.
    if (verbose) { for (int r : reads) { cout << r << endl; } cout << endl; }

}

/**
 *
 * @param data
 */
void work_alt_separate_chaining_hts(vector<RedditElement> &data, bool verbose) {

    /* Perform insertions. */
    // Table Size: 10
    int alt_sc_ht_sz_010_reads = populate_sc_hash_table(data, alt_SC_HashTable);

    // Table Size: 2
    int alt_sc_ht_sz_002_reads = populate_sc_hash_table(data, alt_SC_HT_SZ_002);

    // Table Size: 127
    int alt_sc_ht_sz_127_reads = populate_sc_hash_table(data, alt_SC_HT_SZ_127);

    // Table Size: 233
    int alt_sc_ht_sz_233_reads = populate_sc_hash_table(data, alt_SC_HT_SZ_233);

    // Table Size: 353
    int alt_sc_ht_sz_353_reads = populate_sc_hash_table(data, alt_SC_HT_SZ_353);

    // Table Size: 419
    int alt_sc_ht_sz_419_reads = populate_sc_hash_table(data, alt_SC_HT_SZ_419);


    // Define collection of insertion READS.
    vector<int> reads = {
            alt_sc_ht_sz_010_reads,
            alt_sc_ht_sz_002_reads,
            alt_sc_ht_sz_127_reads,
            alt_sc_ht_sz_233_reads,
            alt_sc_ht_sz_353_reads,
            alt_sc_ht_sz_419_reads
    };


    // Output READS data.
    if (verbose) { for (int r : reads) { cout << r << endl; } cout << endl; }

}



/**
 *
 * @param data
 */
void work_linear_probing_hts(vector<RedditElement> &data, bool verbose) {

    /* Perform insertions. */
    // Table Size: 10
    int lp_ht_sz_010_reads = populate_lp_hash_table(data, LP_HashTable);

    // Table Size: 2
    int lp_ht_sz_002_reads = populate_lp_hash_table(data, LP_HT_SZ_002);

    // Table Size: 127
    int lp_ht_sz_127_reads = populate_lp_hash_table(data, LP_HT_SZ_127);

    // Table Size: 233
    int lp_ht_sz_233_reads = populate_lp_hash_table(data, LP_HT_SZ_233);

    // Table Size: 353
    int lp_ht_sz_353_reads = populate_lp_hash_table(data, LP_HT_SZ_353);

    // Table Size: 419
    int lp_ht_sz_419_reads = populate_lp_hash_table(data, LP_HT_SZ_419);


    // Define collection of insertion READS.
    vector<int> reads = {
            lp_ht_sz_010_reads,
            lp_ht_sz_002_reads,
            lp_ht_sz_127_reads,
            lp_ht_sz_233_reads,
            lp_ht_sz_353_reads,
            lp_ht_sz_419_reads
    };


    // Output READS data.
    if (verbose) { for (int r : reads) { cout << r << endl; } cout << endl; }

}

/**
 *
 * @param data
 */
void work_alt_linear_probing_hts(vector<RedditElement> &data, bool verbose) {

    /* Perform insertions. */
    // Table Size: 10
    int alt_lp_ht_sz_010_reads = populate_lp_hash_table(data, alt_LP_HashTable);

    // Table Size: 2
    int alt_lp_ht_sz_002_reads = populate_lp_hash_table(data, alt_LP_HT_SZ_002);

    // Table Size: 127
    int alt_lp_ht_sz_127_reads = populate_lp_hash_table(data, alt_LP_HT_SZ_127);

    // Table Size: 233
    int alt_lp_ht_sz_233_reads = populate_lp_hash_table(data, alt_LP_HT_SZ_233);

    // Table Size: 353
    int alt_lp_ht_sz_353_reads = populate_lp_hash_table(data, alt_LP_HT_SZ_353);

    // Table Size: 419
    int alt_lp_ht_sz_419_reads = populate_lp_hash_table(data, alt_LP_HT_SZ_419);


    // Define collection of insertion READS.
    vector<int> reads = {
            alt_lp_ht_sz_010_reads,
            alt_lp_ht_sz_002_reads,
            alt_lp_ht_sz_127_reads,
            alt_lp_ht_sz_233_reads,
            alt_lp_ht_sz_353_reads,
            alt_lp_ht_sz_419_reads
    };


    // Output READS data.
    if (verbose) { for (int r : reads) { cout << r << endl; } cout << endl; }

}
