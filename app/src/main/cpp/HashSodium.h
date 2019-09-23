//
// Created by nordo on 23/09/19.
//

//
// Created by nordo on 23/09/19.
//


#include <stdio.h>
#include <iostream>

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#define MESSAGE ((const unsigned char *) "Souri ABDELHALIM")
#define MESSAGE_LEN 16
#define SHORT_DATA ((const unsigned char *) "Sparkling water")
#define SHORT_DATA_LEN 15
#define	MESSAGE_PART1	((const	unsigned	char	*)	"Arbitrary	data	to	hash")
#define	MESSAGE_PART1_LEN	22
#define	MESSAGE_PART2 ((const	unsigned	char	*)	"is	longer	than	expected")
#define	MESSAGE_PART2_LEN	23




#include "libsodium/include/sodium.h"

unsigned  char	hash[crypto_generichash_BYTES];
unsigned char key[crypto_generichash_KEYBYTES];
unsigned char out[crypto_hash_sha256_BYTES];

class HashSodium {
public:

    HashSodium() {
        cout << "hi";
    }

    /**
     *
     * @param b the output
     * @param len teh length of b
     * @return
     */

    char* print_hex(const unsigned char *b, const size_t len)
    {
        char *p;
        p = (char *)malloc(len * 2 + 1);
        /* the library supplies a few utility functions like the one below */
        return sodium_bin2hex(p, len * 2 + 1, b, len);
    }


    string Hash() {
        /**
         * if something went wrong with libsoium
         */
        if (sodium_init() == -1) {
            return "something went wrong with libsoium";
        }
            //
        else {
            /**
             * if it works fine
             * we will call the function crypto_generichash to hash our MESSGAE
             * the MESSGAE is Souri ABDELHALIM
             */

            /**
             * I decare this variable just to convert unsigned char * to string
             */
            std::stringstream buffer;

            /**
             * Call of the method crypto_generichash
             */
            crypto_generichash(out, sizeof(out), MESSAGE, MESSAGE_LEN, NULL, 0) ;

            /**
             * we convert the out of this function to hex
             */
            char * result_hex;
            result_hex = this->print_hex(out,sizeof(out));

            /**
             * convert result_hex variable from char* to string and retunr this string
             * which is the hex out of the hash
             */
            buffer << result_hex << std::endl;
            return buffer.str();

        }
    }


};