using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using MovieBase;

namespace MovieBase.Controllers
{
    public class MoviesGenresController : Controller
    {
        private readonly DBMoviesSQLContext _context;

        public MoviesGenresController(DBMoviesSQLContext context)
        {
            _context = context;
        }

        // GET: MoviesGenres
        public async Task<IActionResult> Index(int genreId)
        {
            var currentGenre = _context.Genres.FirstOrDefault(g => g.Id == genreId);

            if (currentGenre == null)
            {
                return NotFound();
            }

            ViewBag.CurrentGenre = currentGenre;

            var movieDBContext = await _context.MoviesGenres
                .Where(mg => mg.GenreId == genreId)
                .Include(mg => mg.Movie).ToListAsync();

            return View(movieDBContext);
        }

        // GET: MoviesGenres/Details/5
        public async Task<IActionResult> Details(int? id)
        {
            if (id == null || _context.MoviesGenres == null)
            {
                return NotFound();
            }

            var moviesGenre = await _context.MoviesGenres
                .Include(m => m.Genre)
                .Include(m => m.Movie)
                .FirstOrDefaultAsync(m => m.Id == id);
            if (moviesGenre == null)
            {
                return NotFound();
            }

            return View(moviesGenre);
        }

        // GET: MoviesGenres/Create
        public IActionResult Create(int currentGenreId)
        {
            var currentGenre = _context.Genres.FirstOrDefault(g => g.Id == currentGenreId);
            var currentGenreMovieIds = _context.MoviesGenres.Where(mg => mg.GenreId == currentGenreId).Select(mg => mg.MovieId);
            ViewBag.CurrentGenre = currentGenre;
            ViewBag.MoviesList = new SelectList(_context.Movies.Where(m => !currentGenreMovieIds.Contains(m.Id)), "Id", "Name");
            return View();
        }

        // POST: MoviesGenres/Create
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> CreateConfirmed([Bind("Id,MovieId,GenreId")] MoviesGenre moviesGenre)
        {
            Genre genre = _context.Genres.FirstOrDefault(x => x.Id == moviesGenre.GenreId);
            if (ModelState.IsValid)
            {
                Movie movie = _context.Movies.FirstOrDefault(x => x.Id == moviesGenre.MovieId);
                moviesGenre.Movie = movie;
                moviesGenre.Genre = genre;
                _context.Add(moviesGenre);
                await _context.SaveChangesAsync();
                return RedirectToAction(nameof(Index), new { genreId = genre.Id });
            }
            var currentGenreMovieIds = _context.MoviesGenres.Where(mg => mg.GenreId == genre.Id).Select(mg => mg.MovieId);
            ViewBag.GenreId = genre.Id;
            ViewBag.GenreName = genre.Name;
            ViewBag.MoviesList = new SelectList(_context.Movies.Where(m => !currentGenreMovieIds.Contains(m.Id)), "Id", "Name", moviesGenre.MovieId);
            return View(moviesGenre);
        }


        // GET: MoviesGenres/Delete/5
        public async Task<IActionResult> Delete(int? id)
        {
            if (id == null || _context.MoviesGenres == null)
            {
                return NotFound();
            }

            var moviesGenre = await _context.MoviesGenres
                .Include(m => m.Genre)
                .Include(m => m.Movie)
                .FirstOrDefaultAsync(m => m.Id == id);
            if (moviesGenre == null)
            {
                return NotFound();
            }

            ViewBag.CurrentGenre = moviesGenre.Genre;

            return View(moviesGenre);
        }

        // POST: MoviesGenres/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> DeleteConfirmed(int id)
        {
            if (_context.MoviesGenres == null)
            {
                return Problem("Entity set 'DBMoviesSQLContext.MoviesGenres'  is null.");
            }
            var moviesGenre = await _context.MoviesGenres.FindAsync(id);
            if (moviesGenre != null)
            {
                _context.MoviesGenres.Remove(moviesGenre);
            }
            
            await _context.SaveChangesAsync();
            return RedirectToAction(nameof(Index), new { genreId = moviesGenre.GenreId });
        }

        private bool MoviesGenreExists(int id)
        {
          return (_context.MoviesGenres?.Any(e => e.Id == id)).GetValueOrDefault();
        }
    }
}
