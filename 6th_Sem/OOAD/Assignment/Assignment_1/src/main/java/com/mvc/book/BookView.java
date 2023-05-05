package com.mvc.book;

import org.vaadin.crudui.crud.impl.GridCrud;

import com.vaadin.flow.component.applayout.AppLayout;
import com.vaadin.flow.component.html.H1;
import com.vaadin.flow.router.Route;

@Route("/")
public class BookView extends AppLayout {
    public BookView(BookController bookController) {
        H1 title = new H1("Books");
        title.getStyle().set("font-size", "var(--lumo-font-size-l)").set("margin", "var(--lumo-space-m)");
        addToNavbar(title);

        GridCrud<BookModel> crud = new GridCrud<>(BookModel.class, bookController);
        setContent(crud);
    }
}
