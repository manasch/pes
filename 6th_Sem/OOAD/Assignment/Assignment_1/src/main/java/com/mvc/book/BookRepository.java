package com.mvc.book;

import org.springframework.data.mongodb.repository.MongoRepository;

public interface BookRepository extends MongoRepository<BookModel, Long> {
    
}
