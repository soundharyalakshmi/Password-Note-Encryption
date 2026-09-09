# Password Note Encryption

A C-based file encryption and decryption project using password hashing and XOR encryption.

## Project Description

This project provides two operations:

- Encryption: Encrypts a text file using XOR and stores a password hash.
- Decryption: Verifies the password hash and decrypts the file if the password is correct.

## How It Works

### Encryption

1. Read the input text file.
2. Generate a password hash using `password_hash()`.
3. Store the 4-byte hash at the beginning of the output file.
4. Use the first character of the password as the XOR key.
5. Encrypt the file content using XOR.
6. Write the encrypted content to the output file.

### Decryption

1. Read the stored 4-byte hash from the encrypted file.
2. Generate a hash from the entered password.
3. Compare the two hashes.
4. If they match, use the first character of the password as the XOR key.
5. Decrypt the remaining file content.
6. If they don't match, abort the decryption.

## Files

- `main.c` – Handles command-line arguments and identifies the mode.
- `connect.h` – Defines the command information structure and function declarations.
- `auth.c` – Contains the password hashing function.
- `encrypt.c` – Handles file encryption.
- `decrypt.c` – Handles password verification and file decryption.

## How to Compile

```bash
gcc main.c auth.c encrypt.c decrypt.c -o note

## Usage
 - ./note -e input.txt output.enc password
 - ./note -d input.enc output.txt password
