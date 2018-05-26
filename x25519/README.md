## Example of using openssl to generate an X25519 private key

```
make example && ./example > key.pem
cat key.pem
# -----BEGIN PRIVATE KEY-----
# MC4CAQAwBQYDK2VuBCIEICAkIrg/QDl0sdHLi62JzGwioUwi7Kv9cDZ+BMTEDexI
# -----END PRIVATE KEY-----
```

Note you will need to install the latest master of [openssl](https://github.com/openssl/openssl)
by hand on OSX as [X25519 support](https://www.openssl.org/docs/manmaster/man7/X25519.html) is a very recent feature:

```
git clone https://github.com/openssl/openssl ~/dev/tmp/openssl
pushd ~/dev/tmp/openssl
sudo mkdir -p /usr/local/ssl/macos-x86_64
./Configure darwin64-x86_64-cc shared enable-ec_nistp_64_gcc_128 no-ssl2 no-ssl3 no-comp --openssldir=/usr/local/ssl/macos-x86_64
make depend
sudo make install
mkdir -p lib/pkgconfig
mv *.pc lib/pkgconfig
mv *.dylib lib
mv *.a lib
popd
```

