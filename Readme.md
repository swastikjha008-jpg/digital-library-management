# Digital Library Management V2

`Digital Library Management V2` is a cleaner and more functional front-end upgrade of a simple earlier library project.

This version is built as a single-file front-end using:

- `HTML`
- `CSS`
- `JavaScript`

It is designed to feel like a real student project: polished, readable, and useful without becoming too complicated.

## What V2 Improves

Compared to a basic `v1`, this version adds a more complete frontend experience:

- better dashboard layout
- more polished UI
- book images on cards
- unique book IDs
- working add-book feature
- working issue-book feature
- borrower tracking
- 7-day return rule notice
- trending books section

## Features

### 1. Books Catalog

- shows all books in a modern card layout
- each book has:
  - image
  - title
  - author
  - category
  - unique book ID
  - available copies

### 2. Add Book

Users can add a new book through a working modal form.

The form includes:

- book title
- author name
- category
- number of copies
- image URL
- short summary
- trending option

If no image URL is added, the page creates a clean default cover automatically.

### 3. Issue Book

Before issuing a book, the issuer must enter:

- borrower name
- phone number
- optional note

The page also clearly shows this rule:

`The book must be returned in 7 days or a fine applies.`

### 4. Issued Books Tracking

The frontend keeps track of:

- which book was issued
- who borrowed it
- phone number
- issue record ID
- how many days ago it was issued
- how many days remain before the due date

### 5. Trending Books

A dedicated section highlights popular or featured books in a cleaner layout.

### 6. Search and Filters

Users can:

- search books by title
- search by author
- search by category
- search by ID
- filter by:
  - all
  - available
  - issued
  - trending

## Project File

This `v2` runs from one main file:

- `index.html`

## How To Run

1. Open `index.html` in your browser.
2. Search books from the top search bar.
3. Click any book card to view details.
4. Use `Add Book` to add a new book.
5. Use `Issue Book` from the selected book panel.
6. Check the issued tracker to monitor borrowed books.

## Project Structure

```text
digital-library-v2/
├── index.html
+└── README.md
