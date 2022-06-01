using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;

namespace MovieBase
{
    public partial class Genre
    {
        public Genre()
        {
            MoviesGenres = new HashSet<MoviesGenre>();
        }

        public int Id { get; set; }

        [Display(Name = "Назва жанру")]
        public string Name { get; set; } = null!;

        public virtual ICollection<MoviesGenre> MoviesGenres { get; set; }
    }
}
