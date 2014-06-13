//
//  NSString+NACL.h
//  libsodium-objc
//
//  Created by Damian Carrillo on 6/12/14.
//  Copyright (c) 2014 TabbedOut. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NACLCryptoKeyPair.h"
#import "NACLNonce.h"
#import "NACLSymmetricSecretKey.h"
#import "NACLSigningKeyPair.h"

/**
 *  NACL augmentations to NSString.
 */
@interface NSString (NACL)

#pragma mark Public-Key Cryptography

/**
 *  Encrypts and authenticates the receiver (an `NSString` object) using the 
 *  receiving party's public key, the sending party's secret key, and a nonce.
 *  
 *  @param publicKey The receiving party's public key.
 *  @param secretKey The sending party's secret key.
 *  @param nonce     A nonce.
 *  
 *  @return An encrypted data object.
 */
- (NSData *)encryptedDataUsingPublicKey:(NSData *)publicKey 
                              secretKey:(NSData *)secretKey 
                                  nonce:(NACLNonce *)nonce;

/**
 *  Encrypts and authenticates the receiver (an `NSString` object) using the 
 *  receiving party's public key, the sending party's secret key, a nonce, 
 *  and passes back an error to the call site if one occurs.
 *  
 *  @param publicKey The receiving party's public key.
 *  @param secretKey The sending party's secret key.
 *  @param nonce     A nonce.
 *  @param outError  A pointer to an error that the call site will receive.
 *  
 *  @return An encrypted data object.
 */
- (NSData *)encryptedDataUsingPublicKey:(NSData *)publicKey
                              secretKey:(NSData *)secretKey 
                                  nonce:(NACLNonce *)nonce 
                                  error:(NSError **)outError;

#pragma mark Signatures

/**
 *  Signs the receiver (which is an NSData object) using the secret key in the 
 *  signer's supplied `keyPair`.
 *  
 *  @param keyPair  The signer's key pair.
 *  
 *  @return A signed data object.
 */
- (NSData *)signedDataUsingSecretKey:(NSData *)secretKey;

/**
 *  Signs the receiver (which is an NSData object) using the secret key in the 
 *  signer's supplied `keyPair`, and passes back an error to the call site if 
 *  one occurs.
 *  
 *  @param keyPair  The signer's key pair.
 *  @param outError A pointer to an error that the call site will receive.
 *  
 *  @return A signed data object.
 */
- (NSData *)signedDataUsingSecretKey:(NSData *)secretKey 
                               error:(NSError **)outError;

#pragma mark Secret-Key Cryptography

/**
 *  Encrypts and authenticates the receiver (an `NSString` object) using the 
 *  a secret key and a nonce.
 *  
 *  @param secretKey The secret key.
 *  @param nonce     A nonce.
 *  
 *  @return An encrypted data object.
 */
- (NSData *)encryptedDataUsingSecretKey:(NACLSymmetricSecretKey *)secretKey
                                  nonce:(NACLNonce *)nonce;

/**
 *  Encrypts and authenticates the receiver (an `NSString` object) using the 
 *  a secret key, a nonce, and passes back an error to the call site if one 
 *  occurs.
 *  
 *  @param secretKey The secret key.
 *  @param nonce     The nonce.
 *  @param outError  A pointer to an error that the call site will receive.
 *  
 *  @return An encrypted data object.
 */
- (NSData *)encryptedDataUsingSecretKey:(NACLSymmetricSecretKey *)secretKey 
                                  nonce:(NACLNonce *)nonce 
                                  error:(NSError **)outError;

@end
