package com.mvc.book;

import com.vaadin.flow.component.template.Id;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@Getter @Setter @NoArgsConstructor @AllArgsConstructor
public class BookModel {
    @Id
    private Long _id;
    private String title;
    private int pages;
    private String author;
}
