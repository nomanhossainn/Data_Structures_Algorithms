// routes/footer.js
const express = require('express');
const router = express.Router();

router.get('/footer', (req, res) => {
  res.send(`
    <footer class="block border-l-gray-500 bg-red-100">
      <div class="py-10 md:py-12 mx-auto w-full max-w-7xl px-5 md:px-6">
        <div class="md:flex-row flex justify-between sm:items-center sm:flex-col items-start flex-col-reverse">
          <div class="font-semibold mb-4 sm:mb-0 py-1 text-center sm:text-center">
            <a href="#" class="inline-block font-normal text-gray-500 transition hover:text-blue-600 sm:pr-6 lg:pr-12 py-1.5 sm:py-2 pr-6">About</a>
            <a href="#" class="inline-block font-normal text-gray-500 transition hover:text-blue-600 sm:pr-6 lg:pr-12 py-1.5 sm:py-2 pr-6">Features</a>
            <a href="#" class="inline-block font-normal text-gray-500 transition hover:text-blue-600 sm:pr-6 lg:pr-12 py-1.5 sm:py-2 pr-6">Works</a>
            <a href="#" class="inline-block font-normal text-gray-500 transition hover:text-blue-600 sm:pr-6 lg:pr-12 py-1.5 sm:py-2 pr-6">Support</a>
            <a href="#" class="inline-block font-normal text-gray-500 transition hover:text-blue-600 sm:pr-6 lg:pr-12 py-1.5 sm:py-2 pr-6">Help</a>
          </div>
          <p class="text-gray-500 text-sm sm:text-base">© Copyright 2021. All rights reserved.</p>
        </div>
      </div>
    </footer>
  `);
});

module.exports = router;
