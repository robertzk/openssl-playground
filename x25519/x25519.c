/*
 * This file generates an X25519 private key and outputs it to a file using the PEM format.
 */

#include "x25519.h"

void generate_private_key() {
  EVP_PKEY *pkey = NULL;
  EVP_PKEY_CTX *pctx = EVP_PKEY_CTX_new_id(EVP_PKEY_X25519, NULL);
  EVP_PKEY_keygen_init(pctx);
  EVP_PKEY_keygen(pctx, &pkey);
  EVP_PKEY_CTX_free(pctx);
  PEM_write_PrivateKey(stdout, pkey, NULL, NULL, 0, NULL, NULL);
}

int main(int argc, char** argv) {
  generate_private_key();
  return 0;
}

