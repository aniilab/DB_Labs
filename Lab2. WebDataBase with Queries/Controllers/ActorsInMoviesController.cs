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
    public class ActorsInMoviesController : Controller
    {
        private readonly DBMoviesSQLContext _context;

        public ActorsInMoviesController(DBMoviesSQLContext context)
        {
            _context = context;
        }

        // GET: ActorsInMovies
        public async Task<IActionResult> Index(int actorId)
        {
            var currentActor = _context.Actors.FirstOrDefault(d => d.Id == actorId);

            if (currentActor == null)
            {
                return NotFound();
            }

            ViewBag.CurrentActor = currentActor;

            var movieDBContext = await _context.ActorsInMovies
                .Where(am => am.ActorId == actorId)
                .Include(am => am.Movie).ToListAsync();

            return View(movieDBContext);
        }

        // GET: ActorsInMovies/Create
        public IActionResult Create(int currentActorId)
        {
            var currentActor = _context.Actors.FirstOrDefault(a => a.Id == currentActorId);
            var currentActorMovieIds = _context.ActorsInMovies.Where(am => am.ActorId == currentActorId).Select(am => am.MovieId);
            ViewBag.CurrentActor = currentActor;
            ViewBag.MoviesList = new SelectList(_context.Movies.Where(m => !currentActorMovieIds.Contains(m.Id)), "Id", "Name");
            return View();
        }
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> CreateConfirmed([Bind("Id,ActorId,MovieId,Role")] ActorsInMovie actorsInMovie)
        {
            Actor actor = _context.Actors.FirstOrDefault(a => a.Id == actorsInMovie.ActorId);
            if (ModelState.IsValid)
            {
                Movie movie = _context.Movies.FirstOrDefault(m => m.Id == actorsInMovie.MovieId);
                actorsInMovie.Movie = movie;
                actorsInMovie.Actor = actor;
                _context.Add(actorsInMovie);
                await _context.SaveChangesAsync();
                return RedirectToAction(nameof(Index), new { actorId = actor.Id });
            }
            var currentActorMovieIds = _context.ActorsInMovies.Where(am => am.ActorId == actor.Id).Select(am => am.MovieId);
            ViewBag.ActorId = actor.Id;
            ViewBag.ActorName = actor.Name;
            ViewBag.MoviesList = new SelectList(_context.Movies.Where(m => !currentActorMovieIds.Contains(m.Id)), "Id", "Name", actorsInMovie.MovieId);
            return View(actorsInMovie);
        }

        // GET: ActorsInMovies/Delete/5
        public async Task<IActionResult> Delete(int? id)
        {
            if (id == null || _context.ActorsInMovies == null)
            {
                return NotFound();
            }

            var actorsInMovie = await _context.ActorsInMovies
                .Include(a => a.Actor)
                .Include(a => a.Movie)
                .FirstOrDefaultAsync(m => m.Id == id);
            if (actorsInMovie == null)
            {
                return NotFound();
            }

            return View(actorsInMovie);
        }

        // POST: ActorsInMovies/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> DeleteConfirmed(int id)
        {
            var actorsInMovie = await _context.ActorsInMovies.FindAsync(id);
            _context.ActorsInMovies.Remove(actorsInMovie);
            await _context.SaveChangesAsync();
            return RedirectToAction(nameof(Index), new { actorId = actorsInMovie.ActorId });
        }

        private bool ActorsInMovieExists(int id)
        {
          return (_context.ActorsInMovies?.Any(e => e.Id == id)).GetValueOrDefault();
        }
    }
}
