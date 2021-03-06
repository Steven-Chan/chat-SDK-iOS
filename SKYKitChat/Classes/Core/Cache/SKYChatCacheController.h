//
//  SKYChatCacheController.h
//  SKYKitChat
//
//  Copyright 2016 Oursky Ltd.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#import <Foundation/Foundation.h>

#import "SKYChatExtension.h"
#import "SKYMessage.h"

@interface SKYChatCacheController : NSObject

+ (instancetype)defaultController;

- (void)fetchMessagesWithConversationID:(NSString *)conversationId
                                  limit:(NSInteger)limit
                             beforeTime:(NSDate *)beforeTime
                                  order:(NSString *)order
                             completion:(SKYChatFetchMessagesListCompletion)completion;

- (void)fetchMessagesWithIDs:(NSArray<NSString *> *)messageIDs
                  completion:(SKYChatFetchMessagesListCompletion)completion;

- (void)didFetchMessages:(NSArray<SKYMessage *> *)messages
         deletedMessages:(NSArray<SKYMessage *> *)deletedMessages;

- (void)saveMessage:(SKYMessage *)message completion:(SKYChatMessageCompletion)completion;

- (void)didSaveMessage:(SKYMessage *)message error:(NSError *)error;

- (void)didDeleteMessage:(SKYMessage *)message;

- (void)handleRecordChange:(SKYChatRecordChange *)recordChange;

- (void)fetchUnsentMessagesWithConversationID:(NSString *)conversationId
                                   completion:(void (^_Nullable)(NSArray<SKYMessage *> *_Nonnull))
                                                  completion;

@end
