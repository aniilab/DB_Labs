using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;

namespace MovieBase
{
    public partial class MoviesGenre
    {
        public int Id { get; set; }

        [Display(Name ="Фільм")]
        public int MovieId { get; set; }
        [Display(Name = "Жанр")]
        public int GenreId { get; set; }

        [Display(Name = "Жанри")]
        public virtual Genre? Genre { get; set; } = null!;
        [Display(Name = "Фільми")]
        public virtual Movie? Movie { get; set; } = null!;
    }
}
