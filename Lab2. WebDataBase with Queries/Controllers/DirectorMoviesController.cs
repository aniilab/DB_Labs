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
    public class DirectorMoviesController : Controller
    {
        private readonly DBMoviesSQLContext _context;

        public DirectorMoviesController(DBMoviesSQLContext context)
        {
            _context = context;
        }

        // GET: DirectorMovies
        public async Task<IActionResult> Index(int directorId)
        {
            var currentDirector = _context.Directors.FirstOrDefault(d => d.Id == directorId);

            if (currentDirector == null)
            {
                return NotFound();
            }

            ViewBag.CurrentDirector = currentDirector;

            var movieDBContext = await _context.DirectorMovies
                .Where(dm => dm.DirectorId == directorId)
                .Include(dm => dm.Movie).ToListAsync();

            return View(movieDBContext);
        }

        // GET: DirectorMovies/Create
        public IActionResult Create(int currentDirectorId)
        {
            var currentDirector = _context.Directors.FirstOrDefault(d => d.Id == currentDirectorId);
            var currentDirectorMovieIds = _context.DirectorMovies.Where(dm => dm.DirectorId == currentDirectorId).Select(dm => dm.MovieId);
            ViewBag.CurrentDirector = currentDirector;
            ViewBag.MoviesList = new SelectList(_context.Movies.Where(m => !currentDirectorMovieIds.Contains(m.Id)), "Id", "Name");
            return View();
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> CreateConfirmed([Bind("Id,DirectorId,MovieId")] DirectorMovie directorMovie)
        {
            Director director = _context.Directors.FirstOrDefault(d => d.Id == directorMovie.DirectorId);
            if (ModelState.IsValid)
            {
                Movie movie = _context.Movies.FirstOrDefault(m => m.Id == directorMovie.MovieId);
                directorMovie.Movie = movie;
                directorMovie.Director = director;
                _context.Add(directorMovie);
                await _context.SaveChangesAsync();
                return RedirectToAction(nameof(Index), new { directorId = director.Id });
            }
            var currentDirectorMovieIds = _context.DirectorMovies.Where(dm => dm.DirectorId == director.Id).Select(dm => dm.MovieId);
            ViewBag.DirectorId = director.Id;
            ViewBag.DirectorName = director.Name;
            ViewBag.MoviesList = new SelectList(_context.Movies.Where(m => !currentDirectorMovieIds.Contains(m.Id)), "Id", "Name", directorMovie.MovieId);
            return View(directorMovie);
        }

        // GET: DirectorMovies/Delete/5
        public async Task<IActionResult> Delete(int? id)
        {
            if (id == null || _context.DirectorMovies == null)
            {
                return NotFound();
            }

            var directorMovie = await _context.DirectorMovies
                .Include(d => d.Director)
                .Include(d => d.Movie)
                .FirstOrDefaultAsync(m => m.Id == id);
            if (directorMovie == null)
            {
                return NotFound();
            }

            return View(directorMovie);
        }

        // POST: DirectorMovies/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> DeleteConfirmed(int id)
        {
            var directorMovie = await _context.DirectorMovies.FindAsync(id);
            _context.DirectorMovies.Remove(directorMovie);
            await _context.SaveChangesAsync();
            return RedirectToAction(nameof(Index), new {directorId=directorMovie.DirectorId});

        }

        private bool DirectorMovieExists(int id)
        {
          return (_context.DirectorMovies?.Any(e => e.Id == id)).GetValueOrDefault();
        }
    }
}
