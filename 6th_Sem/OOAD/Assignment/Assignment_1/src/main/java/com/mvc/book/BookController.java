package com.mvc.book;

import java.util.List;

import org.springframework.stereotype.Service;
import org.vaadin.crudui.crud.CrudListener;

@Service
public class BookController implements CrudListener<BookModel> {
    private final BookRepository repo;

    public BookController(BookRepository brepo) {
        this.repo = brepo;
    }

    @Override
    public List<BookModel> findAll() {
        return repo.findAll();
    }

    @Override
    public BookModel add(BookModel bookModel) {
        return repo.save(bookModel);
    }

    @Override
    public void delete(BookModel bookModel) {
        repo.delete(bookModel);
    }

    @Override
    public BookModel update(BookModel bookModel) {
        return repo.save(bookModel);
    }

}
