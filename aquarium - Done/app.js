// app.js
const express = require('express');
const path = require('path');

const app = express();
const port = 5321;

// Serve static files (like stylesheets and images)
app.use(express.static(path.join(__dirname, 'public')));

// serve index page
app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, 'index.html'));
});

// serve sea animal images page
app.get('/sea-animals', (req, res) => {
  res.sendFile(path.join(__dirname, 'sea-animals.html'));
});

// serve sea animal quiz page
app.get('/sea-animal-quiz', (req, res) => {
    res.sendFile(path.join(__dirname, 'sea-animal-quiz.html'));
  });

// serve sea animal facts file
app.get('/sea-animal-facts', (req, res) => {
  res.sendFile(path.join(__dirname, 'sea-animal-facts.txt'));
});

app.listen(port, () => {
  console.log(`Server is running at http://localhost:${port}`);
});
