// server.js or routes/banner.js
const express = require('express');
const router = express.Router();
const path = require('path');

router.get('/banner', (req, res) => {
  res.send(`
    <section class="bg-green-200">
      <div class="mx-auto w-full max-w-7xl px-5 py-16 md:px-10 md:py-20">
        <div class="mb-12 flex flex-col md:flex-row">
          <h2 class="mb-8 text-3xl max-w-lg font-bold md:mb-12 md:text-5xl lg:mb-16">
            Find The Right <span>Professionals</span>
          </h2>
        </div>
        <div class="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-4 gap-4">
          <div class="bg-gray-100 rounded-lg py-10 px-5 flex flex-col justify-between h-80">
            <div class="text-xl font-semibold">
              <img class="w-64 h-44" src="/assets/plumber.jpg" alt="" />
            </div>
            <p class="mt-2 text-sm">
              With a perfect blend of experience and passion, Event Connect emerged as a company with
            </p>
          </div>
          <div class="bg-gray-100 rounded-lg py-8 px-5 flex flex-col justify-between h-80">
            <div class="text-xl font-semibold">
              <img class="w-64 h-44" src="/assets/Repair Service .jpeg" alt="" />
            </div>
            <p class="mt-2 text-sm">
              Empower your decisions with our AI-driven predictive analytics, foreseeing market
            </p>
          </div>
          <div class="bg-gray-100 rounded-lg py-8 px-5 flex flex-col justify-between h-80">
            <div class="text-xl font-semibold">
              <img class="w-64 h-44" src="/assets/Electrician.jpeg" alt="" />
            </div>
            <p class="mt-4 text-sm">
              An event itself is an opportunity to display your creation positively.
            </p>
          </div>
          <div class="bg-gray-100 rounded-lg py-4 px-5 flex flex-col justify-between h-80">
            <div class="text-xl font-semibold">
              <img class="w-64 h-44" src="/assets/painter.jpg" alt="" />
            </div>
            <p class="mt-2 text-sm">
              Empower your decisions with our AI-driven predictive analytics, foreseeing market
            </p>
          </div>
        </div>
      </div>
    </section>
  `);
});

module.exports = router;
